*Este proyecto ha sido creado como parte del currículo de 42 por rpedreno*

## Descripción

Este proyecto implementa la función `get_next_line`, que permite leer un archivo línea por línea de forma segura y controlada. La función mantiene una **variable estática** para almacenar el contenido leído entre llamadas consecutivas, lo que permite retomar la lectura exactamente donde se dejó.

El objetivo principal del proyecto es profundizar en la gestión de memoria dinámica, manejo de ficheros y control de buffers en C, así como en la detección y corrección de fugas de memoria.

## Instrucciones

Para probar este proyecto necesitas tener un archivo `.txt` y conocer su descriptor de fichero (`fd`). La función `get_next_line` utilizará este descriptor para leer el archivo línea por línea.

## Compilación

Compila todos los archivos `.c` del proyecto usando:
```
cc -Wall -Werror -Wextra *.c
```
Esto generará un ejecutable (a.out) que podrás ejecutar directamente.
```
./a.out
```
Debes de asugurarte que el archivo `(.txt)` esta en el mismo directorio.

## Recursos
- Artículo utilizado para comprender variables estáticas: (https://www.learn-c.org/es/Static)
- He adoptado un uso correcto de las herramientas de IA que disponemos sobre todo para ver las fugas de memoria que ha sido la tarea más complicada.
- Documentación oficial de C sobre manejo de archivos (`fopen`, `read`, `close`)

## Algoritmo seleccionado

Se utiliza un buffer de tamaño definido (BUFFER_SIZE) para leer fragmentos del archivo.
Cada llamada a get_next_line sigue los pasos:

- Lee hasta BUFFER_SIZE bytes del archivo y los añade a un stash estático que persiste entre llamadas.
- Busca el primer carácter de salto de línea (\n) dentro del stash.
- Extrae la línea completa hasta \n o hasta el final del archivo si no hay salto de línea.
- Actualiza el stash para eliminar la línea ya retornada.
- Devuelve la línea recién leída al usuario.
