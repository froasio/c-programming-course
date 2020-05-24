#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t convertir_segundos(uint segundos_totales, 
                            uint *h, 
                            uint *m, 
                            uint *s);

int main(void) {
    uint segundos = 4000;
    uint h, m, s;

    convertir_segundos(segundos, &h, &m, &s);

    printf("H: %d, M: %d, S: %d \n", h, m, s);

	return EXIT_SUCCESS;
} 

status_t convertir_segundos(uint segundos_totales, 
                            uint *h, 
                            uint *m, 
                            uint *s) {
    
    if (h == NULL || m == NULL || s == NULL){
        return ERROR_NULL_POINTER;
    }
    
    *h = segundos_totales / 3600;
    *m = (segundos_totales % 3600) / 60;
    *s = segundos_totales % 60;

    return OK;
}
