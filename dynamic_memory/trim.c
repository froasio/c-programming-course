#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_OUT_OF_MEMORY
} status_t;

status_t left_trim(char **ss, const char *s);
status_t right_trim(char **ss, const char *s);

int main(void) {

	char s[] = "     hola";
	char t[] = "hola     ";
	char *ls, *rs;
	status_t st;

	st = left_trim(&ls, s);
	if(st != OK) {
		/*Informar un error por stdout en función del status*/
		return st;
	}

	printf("'%s'\n", s);
	printf("'%s'\n", ls);

	st = right_trim(&rs, t);
	if(st != OK) {
		/*Informar un error por stdout en función del status*/
		free(ls);
		return st;
	}

	printf("'%s'\n", t);
	printf("'%s'\n", rs);

	free(ls);
	free(rs);
	return 0;
}

status_t left_trim(char **ss, const char *s) {
	
	size_t i;
	if(s == NULL || ss == NULL)
		return ERROR_NULL_POINTER;
	
	for(i = 0; isspace(s[i]); i++);

	*ss = (char*) malloc(sizeof(char)*(strlen(s)-i+1));
	if(*ss == NULL)
		return ERROR_OUT_OF_MEMORY;

	memcpy(*ss, &(s[i]), strlen(s) - i + 1);

	return OK;
}

status_t right_trim(char **ss, const char *s) {

	int i;

	if(s == NULL || ss == NULL)
		return ERROR_NULL_POINTER;

	for(i = strlen(s) - 1; i >= 0 && isspace(s[i]); i--);

	*ss = (char*) malloc(sizeof(char)*(strlen(s)-i+1));

	if(*ss == NULL)
		return ERROR_OUT_OF_MEMORY;

	memcpy(*ss, s, strlen(s) - i);
	(*ss)[i+1] = '\0';

	return OK;

}
