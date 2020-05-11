#include <stdio.h>
#include <stdlib.h>
#define N 7
typedef enum {
  FALSE,
  TRUE
} bool_t;

int main(void) {

	int v[N] = {-1,4,1,-5,1,-4,2};
  int target = 10;
  size_t i, j;
  bool_t found_target = FALSE;

  /*Algoritmo*/
  for (i=0; i<N; i++){
    for (j=i+1; j<N; j++){
      if (v[i]+v[j]==target){
        found_target = TRUE;
        break;
      }
    }
  }
  
  switch(found_target) {
    case FALSE:
      printf("No existe un par que sume el objetivo \n");
      break;
    case TRUE:
      printf("Existe un par que sume el objetivo \n");
      break;
  }

  return EXIT_SUCCESS;

}