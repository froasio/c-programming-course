/*
Escribir un programa que lea un número entero positivo e imprima por stdout los números naturales
impares menores que él. 
*/

#include <stdio.h>
#define MSG_USR "Ingrese un número entero positivo:"
#define ERROR_MSG "ERROR"
#define ERROR_NOT_POSITIVE_NUMBER "número no positivo"
#define ERROR_NOT_A_NUMBER "no se pudo interpretar un número entero"

int main(void) {

  int numero_ingresado;
  int i;

  puts(MSG_USR);

  if(!scanf("%d", &numero_ingresado)) {
    fprintf(stderr, "%s : %s \n", ERROR_MSG, ERROR_NOT_A_NUMBER);
    return 1;
  }
  
  if(numero_ingresado < 1) {
    fprintf(stderr, "%s : %s \n", ERROR_MSG, ERROR_NOT_POSITIVE_NUMBER);
    return 1;
  }

  for(i = 1; i < numero_ingresado; i += 2 ) {

    printf("%d \n", i);
    
  }
  
	return 0;
}