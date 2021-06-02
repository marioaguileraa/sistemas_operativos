# Sistemas Operativos - Práctica 1 - make

## Tareas a realizar

Tras las explicaciones en las clases de laboratorio, el alumno debe ser capaz
de producir un `Makefile` que genere automáticamente un ejecutable de la manera
más óptima sin mas que invocar a `make` sin argumentos.

En este directorio encontrará las fuentes de un programa simple que calcula el
factorial de un número entero que se pasa como parámetro, compuesto por tres
archivos fuente en C y dos archivos de cabecera.

1. Realice un `makefile` que cumpla con lo anterior. El archivo debe además
incluir un target llamado `clean` para borrar el ejecutable y los objetos
cuando se invoque con `make clean`, y un target `all` adecuado al principio del
archivo.
