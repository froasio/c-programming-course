#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_SIZE 10

typedef struct {
	size_t l; /* Longitud efectiva */
	size_t a; /* Memoria reservada */
	char *s;
} string_t;

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_NO_MEMORY,
	ERROR_OUT_OF_RANGE
} status_t;

status_t ADT_string_create_alloc(string_t **s, size_t alloc);
status_t ADT_string_destroy(string_t **s);
status_t ADT_string_create_from_cstr(string_t **s, const char* cs);
size_t ADT_string_get_length(string_t *s);
status_t ADT_string_print(string_t *s, FILE *);

/*

	status_t ADT_string_create_from_file(string_t **s, FILE *f);
	status_t ADT_string_create_clone(string_t **s, const string_t *cs);
	status_t ADT_string_print_sub(string_t *s, size_t b, 	size_t e);
	status_t ADT_string_sub_string(string_t **ss, const string_t *s, size_t b, size_t e);
	status_t ADT_string_char_at(string_t *s, size_t i, int* char_at);
	status_t ADT_string_to_cstr(char **cs, string_t *s);
	status_t ADT_string_compare(string_t *s1, string_t *s2, int *cmp);

*/

int main(void) {

	char cs[] = "hola";
	string_t *s;

	ADT_string_create_from_cstr(&s, cs);
	ADT_string_print(s, stdout);
	putchar('\n');
	printf("%lu\n", ADT_string_get_length(s));
	ADT_string_destroy(&s);

	return EXIT_SUCCESS;

}

status_t ADT_string_create_alloc(string_t **s, size_t alloc){

	if(s == NULL)
		return ERROR_NULL_POINTER;
	
	*s = (string_t*)malloc(sizeof(string_t));
	if(*s == NULL)
		return ERROR_NO_MEMORY;

	(*s)->s = (char*) malloc(alloc * sizeof(char));
	if((*s)->s == NULL){
		free(*s);
		return ERROR_NO_MEMORY;
	}
		
	(*s)->l = 0;
	(*s)->a = alloc;
	return OK;

}

status_t ADT_string_destroy(string_t **s){

	if(s == NULL)
		return ERROR_NULL_POINTER;

	free((*s)->s);
	(*s)->s = NULL;
	(*s)->a = 0;
	(*s)->l = 0;
	free(*s);
	*s = NULL;
	return OK;

}

status_t ADT_string_create_from_cstr(string_t **s, const char* cs){

	size_t l,i;
	status_t st;

	if(s == NULL || cs == NULL)
		return ERROR_NULL_POINTER;

	l = strlen(cs);

	st = ADT_string_create_alloc(s, l);
	if(st != OK)
		return st;

	for(i=0; i < l; i++){
		(*s)->s[i] = cs[i];
	}
	(*s)->l = l;
	return OK;

}

size_t ADT_string_get_length(string_t *s){
	return s->l;
}

status_t ADT_string_print(string_t *s, FILE *f){

	size_t i;

	if(s == NULL || f == NULL)
		return ERROR_NULL_POINTER;

	for(i = 0; i < s->l; i++)
		fputc(s->s[i], f);

	return OK;

}
