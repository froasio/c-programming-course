#include <stdlib.h>
#include "split.h"

status_t delete_string_array(char*** ss, size_t l) {
	size_t i;

	for(i = 0; i < l; i++) {
		free((*ss)[i]);
		(*ss)[i] = NULL;
	}
	free(*ss);
	*ss = NULL;
	return OK;

}

char* strdup_n(const char* s, size_t i, size_t n) {

	char* ss;
	size_t k;
	if(s == NULL)
		return NULL;

	ss = (char*) malloc((n+1)*sizeof(char));
	if(ss == NULL)
		return NULL;

	for(k = 0; k < n; i++, k++) {			
		ss[k] = s[i];
	}
	ss[n] = '\0';

	return ss;
}

status_t split(const char* s, const char del, char*** ss, size_t *len) {

	size_t i,j,l,ll;

	if(s == NULL || ss == NULL || len == NULL)
		return ERROR_NULL_POINTER;

	for(i = 0, *len = 1; s[i]; i++)
		if(s[i] == del)
			(*len)++;
	ll = i;

	*ss = (char**) malloc((*len) * sizeof(char*));
	if(*ss == NULL)
		return ERROR_OUT_OF_MEMORY;

	for(i = 0, j = 0, l = 0; j <= ll; ){

		if(s[j] == del || !s[j]) {
			(*ss)[l] = strdup_n(s, i, j-i);
			if((*ss)[l] == NULL) {
				delete_string_array(ss, l);
				return ERROR_OUT_OF_MEMORY;
			}
			i = j + 1;
			l++;
		}
		j++;
	}

	return OK;

}