#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 10

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t cargar_arreglo_aleatorio(int v[], size_t n);
status_t imprimir_arreglo(int v[], size_t n);

int main(void) {
    
    int v[M];

    if(cargar_arreglo_aleatorio(v, M) != OK) {
      fprintf(stderr, "Error \n");
      return EXIT_FAILURE;
    }

    if(imprimir_arreglo(v, M) != OK) {
      fprintf(stderr, "Error \n");
      return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

} 

status_t cargar_arreglo_aleatorio(int v[], size_t n){
    
    size_t i;
    if(v == NULL)
        return ERROR_NULL_POINTER;
		
		srand(time(NULL));
    for(i = 0; i < n; i++) {
        v[i] = (rand() % 10) + 1;
    }

    return OK;
}

status_t imprimir_arreglo(int v[], size_t n) {
    
    size_t i;
    if(v == NULL)
        return ERROR_NULL_POINTER;

    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    putchar('\n');

    return OK;

}
