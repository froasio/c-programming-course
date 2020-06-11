#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_OUT_OF_MEMORY
} status_t;

char* strdup(const char* s);
status_t strdup_status(char **,const char *);

int main(void) {

	char s[] = "Hola :)";
	char *s1, *s2;
	status_t st;

	s1 = strdup(s);
	if(s1 == NULL) {
		/*TODO: Imprimir algún mensaje de error por stdout*/
		return EXIT_FAILURE;
	}
	puts(s1);

	st = strdup_status(&s2, s);
	if(st != OK) {
		/*TODO: Imprimir algún mensaje de error en función del st por stdout*/
		free(s1);
		return st;
	}
	puts(s2);

	free(s1);
	free(s2);
	return EXIT_SUCCESS;
}

char* strdup(const char* s) {
	
	char *ss;

	if(s == NULL)
		return NULL;

	ss = (char *) malloc(sizeof(char) * (strlen(s)+1));
	if(ss == NULL){
		return NULL;
	}

	strcpy(ss, s);

	return ss;

}

status_t strdup_status(char **ss, const char *s) {

	if(s == NULL || ss == NULL)
		return ERROR_NULL_POINTER;

	*ss = (char *) malloc(sizeof(char) * (strlen(s)+1));

	if(*ss == NULL)
		return ERROR_OUT_OF_MEMORY;

	strcpy(*ss, s);

	return OK;
}
