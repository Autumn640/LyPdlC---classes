# Convenciones para este repo (C++)

**Regla de oro:** una carpeta por ejercicio/tema, y **solo un `main()` por carpeta**.

Cuando el profesor pida crear una clase nueva, o empecemos un tema nuevo:

1. Crear una carpeta nueva: `clase-XX-nombre-tema/`
2. Dentro, un `main.cpp` con el punto de entrada del ejercicio.
3. Si se necesita una clase, crear dos archivos:
   - `NombreClase.h` — declaración (con guard `#ifndef/#define/#endif`)
   - `NombreClase.cpp` — implementación (**todo método declarado en el `.h` necesita su cuerpo aquí**, o el linker falla con `LNK2019`)
4. Copiar la carpeta `.vscode/tasks.json` de un ejercicio anterior con clases (usa `*.cpp` — compila automáticamente todos los `.cpp` de la carpeta).

## Estructura actual

- `clase-01-punteros/` — punteros, referencias, aritmética de punteros (un solo archivo, sin clases).
- `clase-02-clases/` — primera clase (`Student`), constructor, lectura de input con `cin`/`getline`.

## Notas rápidas

- Si usas `cin >>` y luego `getline`, agrega `cin >> ws` antes del `getline` para descartar el salto de línea sobrante.
- Si los acentos salen mal en la terminal (`est├í` en vez de `está`), correr `chcp 65001` antes de ejecutar el `.exe`.
- Lanza VS Code desde "Developer Command Prompt for VS 2019" (`code .`) si `cl.exe` no es reconocido en la terminal.

## Build task (importante)

El archivo `.vscode/tasks.json` debe estar en la **raíz del repo** (la carpeta que abres con "Open Folder" en VS Code), no dentro de cada carpeta de clase. VS Code solo lee el `.vscode` de la carpeta raíz que tienes abierta — si lo pones dentro de `clase-02-clases/`, VS Code lo ignora si abriste el repo completo.

La tarea usa `${fileDirname}\*.cpp`, que se ajusta automáticamente a la carpeta del archivo activo. Así que un solo `tasks.json` en la raíz funciona para `clase-01-punteros`, `clase-02-clases`, y cualquier carpeta nueva — sin tener que editarlo cada vez.

⚠️ Esto implica que **cada carpeta de clase debe tener un solo archivo con `main()`**. Si dos archivos con `main()` quedan en la misma carpeta, el wildcard los compila juntos y falla con "multiple definition of main".

## ¿Por qué no usar `#include "Clase.cpp"` en vez de compilar por separado?

Es una alternativa que sí compila, pero no es lo correcto:

1. **Rompe la compilación separada.** El punto de tener `.h`/`.cpp` separados es que cada archivo se compila una sola vez y se puede reutilizar en varios programas sin recompilar todo cada vez. Incluir el `.cpp` como texto elimina esa ventaja.
2. **Causa errores de "multiple definition"** en el linker si dos archivos distintos terminan incluyendo el mismo `.cpp` (directa o indirectamente) y se compilan juntos — un error común una vez que empiezas a tener varias clases relacionadas.
3. **No es lo que pide el ejercicio.** La separación `.h`/`.cpp` es justamente lo que el profesor quiere que entendamos.

Modelo mental correcto:
- `#include "Clase.h"` → "necesito saber qué puede hacer esta clase" (va en cualquier archivo que *usa* la clase).
- `Clase.cpp` → "así es como funciona por dentro" — se compila por separado y se enlaza (link) al final; nunca se incluye como texto en otro archivo.

El wildcard en `tasks.json` no es un atajo — le dice al compilador que compile cada archivo por separado y los enlace al final, que es el modelo de compilación correcto en C++ (no un workaround).
