#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 5
#define CMD_ARG_POS_FIRST_VALUE_TOKEN 1
#define CMD_ARG_FIRST_VALUE_TOKEN "-a"
#define CMD_ARG_POS_SECOND_VALUE_TOKEN 3
#define CMD_ARG_SECOND_VALUE_TOKEN "-b"
/*
    federoasio@gmail.com
    ./cla_a -a 1 -b 2
    3
*/

typedef enum {OK, ERROR_NULL_POINTER, ERROR_INVOCATION} status_t;

status_t validate_arg(int argc, char *argv[], int *a, int *b);

int main (int argc, char *argv[]){

    int a, b, suma;
    status_t st;

    st = validate_arg(argc, argv, &a, &b);

    if(st != OK) {
        fprintf(stderr, "%s %s \n", "ERROR:", "Invocacion incorrecta");
        return st;
    }

    suma = a + b;

    printf("%d\n", suma);
    
    return EXIT_SUCCESS;
}

status_t validate_arg(int argc, char *argv[], int *a, int *b) {
    
    char *tmp;
    if(argc != MAX_ARGS) {
        return ERROR_INVOCATION;
    }
    /*validar punteros*/
    if(strcmp(argv[CMD_ARG_POS_FIRST_VALUE_TOKEN], CMD_ARG_FIRST_VALUE_TOKEN)) {
        return ERROR_INVOCATION;
    }

    *a = strtol(argv[CMD_ARG_POS_FIRST_VALUE_TOKEN + 1], &tmp, 10);
    if(*tmp) {
        return ERROR_INVOCATION;
    }

    if(strcmp(argv[CMD_ARG_POS_SECOND_VALUE_TOKEN], CMD_ARG_SECOND_VALUE_TOKEN)) {
        return ERROR_INVOCATION;
    }

    *b = strtol(argv[CMD_ARG_POS_SECOND_VALUE_TOKEN + 1], &tmp, 10);
    if(*tmp) {
        return ERROR_INVOCATION;
    }

    return OK;
}
