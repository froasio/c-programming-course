#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 5
#define CMD_ARG_POS_FIRST_VALUE_TOKEN 1
#define CMD_ARG_FIRST_VALUE_TOKEN "-t"
#define CMD_ARG_POS_SECOND_VALUE_TOKEN 3
#define CMD_ARG_SECOND_VALUE_TOKEN "-z"
/*
    ./cla_validations -a 1 -b 2
		./cla_validations -b 1 -a 1
    3
*/

typedef enum {OK, ERROR_NULL_POINTER, ERROR_INVOCATION} status_t;

status_t validate_arg_fixed_position(int argc, char *argv[], int *a, int *b);
status_t validate_arg_dinamic_position(int argc, char *argv[], int *a, int *b);

int main (int argc, char *argv[]){

    int a, b, suma;
    status_t st;

    st = validate_arg_dinamic_position(argc, argv, &a, &b);

    if(st != OK) {
        fprintf(stderr, "%s %s \n", "ERROR:", "Invocacion incorrecta");
        return st;
    }

    suma = a + b;

    printf("%d\n", suma);
    
    return EXIT_SUCCESS;
}

status_t validate_arg_fixed_position(int argc, char *argv[], int *a, int *b) {
    
    char *tmp;
	
		if(a == NULL || b == NULL || argv == NULL){
			return ERROR_NULL_POINTER;
		}

		/* Siempre validar argc */
    if(argc != MAX_ARGS) {
        return ERROR_INVOCATION;
    }
		/* Validación de las banderas de la opción */
    if(strcmp(argv[CMD_ARG_POS_FIRST_VALUE_TOKEN], CMD_ARG_FIRST_VALUE_TOKEN)) {
        return ERROR_INVOCATION;
    }
		/* Traducción de los valores*/
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

status_t validate_arg_dinamic_position(int argc, char *argv[], int *a, int *b) {
	char *tmp;
	size_t i;
	int args_to_parse;

	if(a == NULL || b == NULL || argv == NULL){
		return ERROR_NULL_POINTER;
	}

	/* Siempre validar argc */
	if(argc != MAX_ARGS) {
			return ERROR_INVOCATION;
	}

	for(i = 1, args_to_parse = MAX_ARGS - 1; i < argc - 1; i += 2) {
		if(!strcmp(argv[i], CMD_ARG_FIRST_VALUE_TOKEN)) {
			/* Traducción de los valores*/

			*a = strtol(argv[i + 1], &tmp, 10);
			if(*tmp) {
					return ERROR_INVOCATION;
			}
			args_to_parse -= 2;
		}

		if(!strcmp(argv[i], CMD_ARG_SECOND_VALUE_TOKEN)) {
			*b = strtol(argv[i + 1], &tmp, 10);
			if(*tmp) {
					return ERROR_INVOCATION;
			}
			args_to_parse-=2;
    }
	}

	if(args_to_parse != 0) {
		return ERROR_INVOCATION;
	}
	
 return OK;
}