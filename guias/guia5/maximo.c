#include <stdio.h>
#include <stdlib.h>

/*
  Escribir una función que calcule el maximo de un arreglo de enteros.
  - Validar arreglo nulo
  - Devolver el valor maximo y la posición del arreglo en la que se encuentra
*/

#define ARRAY_LENGTH 5

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t max_array(int t[], size_t l, int *max, size_t *i_max);

int main(void) {
  int arr[ARRAY_LENGTH] = {1,30,5,6,6};
  int max;
  size_t i_max;
  
  if(max_array(arr, ARRAY_LENGTH, &max, &i_max) != OK) {
    fprintf(stderr, "Error \n");
    return EXIT_FAILURE;
  }
  
	printf("max: %d i: %lu", max, i_max);
	
  return EXIT_SUCCESS;

}

status_t max_array(int t[], size_t l, int *max, size_t *i_max) { 
  size_t i;

  if(t == NULL || i_max  == NULL || max == NULL) 
    return ERROR_NULL_POINTER; 
  
  *i_max = 0;

  for( i = 0 ; i < l ; i++) {
    if(t[i]> t[*i_max]) {
      *i_max = i;
    }
  }  
  *max = t[*i_max];

  return OK;
}