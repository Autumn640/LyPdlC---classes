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
