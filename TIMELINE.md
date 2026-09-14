# Timeline — configuración inicial de C++ en VS Code

Registro de los problemas que aparecieron al configurar el entorno de C++ por primera vez, y cómo se resolvieron. Sirve como referencia si algo similar vuelve a pasar.

## 1. Espacios en nombres de carpetas
**Síntoma:** `LNK1181: no se puede abrir el archivo de entrada` — el linker no encontraba el `.obj`.
**Causa:** carpetas como `frist class c++` (con espacios) rompían el comando de build, que no las pasaba entre comillas correctamente.
**Solución:** renombrar carpetas/archivos usando guiones en vez de espacios (`frist-class-c++`).

## 2. `cl.exe` no reconocido / falla silenciosa
**Síntoma:** mismo error de `.obj` faltante incluso sin espacios en las rutas.
**Causa:** `cl.exe` (el compilador de MSVC) necesita variables de entorno que solo se cargan dentro de una terminal especial ("Developer Command Prompt for VS 2019"). En una terminal normal, `cl.exe` no compila nada, así que nunca se genera el `.obj`.
**Solución:** abrir "Developer Command Prompt for VS 2019" desde el menú Inicio, navegar a la carpeta del proyecto, y ejecutar `code .` desde ahí para que VS Code herede ese entorno.

## 3. Solo se compilaba un archivo
**Síntoma:** `LNK2019: símbolo externo sin resolver` para `Student::Student()` y `Student::estudiar()`.
**Causa:** la tarea de build por defecto ("build active file") solo compila el archivo abierto (`main.cpp`), nunca `Student.cpp`, aunque `main.cpp` use esa clase.
**Solución:** cambiar `tasks.json` para compilar todos los `.cpp` de la carpeta usando un wildcard (`${fileDirname}\*.cpp`), no solo `${file}`.

## 4. Constructor declarado pero nunca implementado
**Síntoma:** el mismo error LNK2019, pero específicamente para el constructor.
**Causa:** `Student.h` declaraba `Student();` pero `Student.cpp` nunca tenía el cuerpo `Student::Student() { ... }`.
**Solución:** agregar la implementación del constructor en el `.cpp`. Regla general: todo lo declarado en el `.h` necesita su cuerpo en el `.cpp`.

## 5. `cin >>` con texto de varias palabras
**Síntoma:** al escribir "ing sistemas" como carrera, los campos siguientes (`edad`, `semestre`) salían en blanco o con basura.
**Causa:** `cin >>` solo lee una palabra a la vez; "sistemas" quedaba pendiente en el buffer y rompía la siguiente lectura numérica, dejando `cin` en estado de error.
**Solución:** usar `cin >> ws` seguido de `getline(cin, variable)` para campos de texto que puedan tener espacios.

## 6. Acentos rotos en la terminal (`est├í` en vez de `está`)
**Síntoma:** vocales acentuadas y "ñ" se veían como caracteres extraños.
**Causa:** desajuste entre la codificación del archivo (UTF-8) y la página de códigos de la terminal.
**Solución:** ejecutar `chcp 65001` en la terminal antes de correr el `.exe`. Es solo visual, no afecta el programa.

## 7. Dos archivos con `main()` en la misma carpeta
**Síntoma:** riesgo de "multiple definition of main" al usar el wildcard de compilación.
**Causa:** `First-c++-class.cpp` (ejercicio de punteros) y `First-project-in-c++.cpp` (ejercicio de clases) estaban en la misma carpeta.
**Solución:** reorganizar el repo en una carpeta por tema/ejercicio (`clase-01-punteros/`, `clase-02-clases/`, etc.), cada una con un solo `main()`.

## 8. El wildcard "no funcionaba" después de reorganizar
**Síntoma:** el build solo compilaba `main.cpp`, ignorando `Student.cpp`, aunque el `tasks.json` correcto existía dentro de `clase-02-clases/.vscode/`.
**Causa:** VS Code solo lee el `.vscode/tasks.json` de la carpeta que está abierta como raíz del workspace (File > Open Folder). Al abrir el repo completo, ese `tasks.json` interno se ignoraba.
**Solución:** mover el `tasks.json` con wildcard a la raíz real del repo (la carpeta que se abre en VS Code). Como usa `${fileDirname}`, se ajusta automáticamente a la carpeta del archivo activo, sin importar en qué subcarpeta se esté trabajando.
