# c-programming-course
[![Run on Repl.it](https://repl.it/badge/github/froasio/c-programming-course)](https://repl.it/github/froasio/c-programming-course)

## Clase 0
- Comandos de shell de Unix: cat, ls, wc -l, rm, cp, mkdir, rmdir, mv, cd, date, pwd
- Comandos de shell de Windows: type, dir, del, copy (xcopy), md, rd, move, cd, date (los mencionamos por arriba)

## Clase 1
- Permisos en UNIX, chmod (owner, group, others)
- Diagramas de flujo
- Hola Mundo

## Clase 2
- Ejercicios Guia 1
- Piping y redirección de flujo (>, >>, |, tee)
- Continuación diagramas de flujo 
- Break, Continue y size_t
- Representación interna de los datos (Capítulo 2 - K&R)

## Clase 3
- Caracteres ASCII
- Tipos de datos flotantes
- Tipos enumerativos (guia 2)
- Arreglos y cadenas de caracteres (guia 3)
- Ejercicios guia 1

## Clase 4
- Cadenas de caracteres (guia 3)
- Punteros (guia 4)

## Clase 5
- Ejercicio entregable
-- Crear cuenta en github.com
-- Crear cuenta en repl.it con cuenta de github.com
-- Entrar en el link y hacer el ejercicio
- Ejercicios funciones
- Funciones atoxx()

## Clase 6
- Makefile
- Modificadores static y extern
- Ejercicios de operadores de bits

## Clase 7

 strdup()
char * strdup(const char *);
status_t strdup(const char *, char \*\*);

 left-trim()/right_trim() con memoria dinámica

 función de destrucción de una matriz dinámica:
status_t delete_matrix (double \*\*, size_t n_rows, size_t n_cols);
status_t delete_matrix (double \*\*\*, size_t n_rows, size_t n_cols);

 función constructora de una matriz dinámica:
double \*\* create_matrix (size_t n_rows, size_t n_cols);
status_t create_matrix (size_t n_rows, size_t n_cols), double \*\*\*);

## Clase 8
- Ejemplos CLA
-- Validar argv y argc (dentro de main.c)
-- argv es de solo lectura
- Clonación de estructuras anidadas y referenciadas

## Disclaimer
*Este repositorio solamente representa las notas que usamos para explicar la resolución de ejercicios en clase que van a acompañados por explicaciones y muchas modificaciones en vivo de los programas que hacemos. Bajo ningún punto de vista representan soluciones finales o completas de los ejercicios.*
