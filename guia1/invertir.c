/*
Escribir un programa que invierta los dígitos de un número positivo entero (sugerencia: usar operadores módulo, %, y división, /, para obtener los dígitos de a uno por vez). 

  Ej:
    11234 => 43211

*/


#include <stdio.h>
#define MSG_USR "Ingrese un número entero positivo:"
#define ERROR_MSG "ERROR"
#define ERROR_NOT_POSITIVE_NUMBER "número no positivo"
#define ERROR_NOT_A_NUMBER "no se pudo interpretar un número entero"

int main(void) {

  int n;
  int x;

  puts(MSG_USR);

  if(!scanf("%d", &n)) {
    fprintf(stderr, "%s : %s \n", ERROR_MSG, ERROR_NOT_A_NUMBER);
    return 1;
  }
  
  if(n < 1) {
    fprintf(stderr, "%s : %s \n", ERROR_MSG, ERROR_NOT_POSITIVE_NUMBER);
    return 1;
  } 

  x = 0;
  while(n) {
    x = x * 10 + n % 10;
    n = n / 10;
  }

  printf("%d \n", x);
  
	return 0;
}