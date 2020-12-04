#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define STATUS_MESSAGE_OK "OK"
#define STATUS_MESSAGE_ERROR_NULL_POINTER "ERROR NULL POINTER"

typedef unsigned int uint;
typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

char *status_messages[] = {
	STATUS_MESSAGE_OK,
	STATUS_MESSAGE_ERROR_NULL_POINTER
};

status_t convertir_segundos(uint segundos_totales, 
                            uint *h, 
                            uint *m, 
                            uint *s);

int main(void) {
    uint segundos = 4000;
    uint h, m, s;
		status_t st;

    st = convertir_segundos(segundos, &h, &m, &s);
		if(st != OK) {
			fprintf(stderr, "%s", status_messages[st]);
			return st;
		}

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
