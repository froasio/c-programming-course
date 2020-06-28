#ifndef SPLIT_H
#define SPLIT_H

typedef enum {
	ERROR_OUT_OF_MEMORY,
	ERROR_NULL_POINTER,
	OK
} status_t;

status_t delete_string_array(char*** ss, size_t l);
char* strdup_n(const char* s, size_t i, size_t n);
status_t split(const char* s, const char del, char*** ss, size_t *len);

#endif