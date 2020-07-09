/*

*/


#include <stdio.h>
#define MSG_USR "Ingrese un número no negativo:"
#define ERROR_MSG "ERROR"
#define ERROR_NEGATIVE_NUMBER "número negativo"
#define ERROR_NOT_A_NUMBER "no se pudo interpretar un número entero"

int main(void) {

  int n;
  size_t i,f;

  /*puts(MSG_USR);*/

  if(!scanf("%d", &n)) {
    fprintf(stderr, "%s : %s \n", ERROR_MSG, ERROR_NOT_A_NUMBER);
    return 1;
  }
  
  if(n < 0) {
    fprintf(stderr, "%s : %s \n", ERROR_MSG, ERROR_NEGATIVE_NUMBER);
    return 1;
  } 

  f = 1;
  for(i = 1; i <= n; i++) {
    f *= i;
  }
  
  printf("%lu \n", f);

	return 0;
}