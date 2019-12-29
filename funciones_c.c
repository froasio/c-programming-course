#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 10

void cargar_arreglo_aleatorio(int v[], size_t n);
void imprimir_arreglo(int v[], size_t n);

int main(void) {
    
    int v[M];

    cargar_arreglo_aleatorio(v, M);

    imprimir_arreglo(v, M);

    return 0;

} 

void cargar_arreglo_aleatorio(int v[], size_t n){
    size_t i;
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        v[i] = rand() % 10 + 1;
    }
}
void imprimir_arreglo(int v[], size_t n) {
    size_t i;
    if(v == NULL)
        return void;

    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    putchar('\n');
}
