#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

status_t read_line (FILE *f, char **s, bool_t *eof) {
	size_t allocated_size, used_size;
	char * aux;
	int c;

	if (s == NULL || eof == NULL)
		return ERROR_NULL_POINTER;

	if ((*s = malloc(INIT_CHOP)) == NULL)
		return ERROR_OUT_OF_MEMORY;

	allocated_size = INIT_CHOP;
	used_size = 0;
	while ((c = fgetc(f)) != LF && !feof(f)) {

		if (used_size == allocated_size - 1) {
			if ((aux = realloc(*s, allocated_size * GROWTH_FACTOR)) == NULL) {
				free(*s);
				*s = NULL;
				return ERROR_OUT_OF_MEMORY;
			}
			*s = aux;
			allocated_size *= GROWTH_FACTOR;
		}
		(*s)[used_size++] = c;
	}	
	(*s)[used_size] = NUL;
	(*eof) = feof(f) ? TRUE : FALSE;

	return OK;

}
