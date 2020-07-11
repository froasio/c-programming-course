#ifndef READ_LINE_H
#define READ_LINE_H
#define INIT_CHOP 2
#define GROWTH_FACTOR 2
#define LF '\n'
#define NUL '\0'

typedef enum {
	ERROR_OUT_OF_MEMORY,
	ERROR_NULL_POINTER,
	OK
} status_t;

typedef enum {
	FALSE,
	TRUE
} bool_t;

status_t read_line (FILE *f, char **s, bool_t *eof);

#endif