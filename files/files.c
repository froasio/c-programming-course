#include <stdio.h>
#include <stdlib.h>

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_OUT_OF_MEMORY,
	ERROR_OPENING_FILE,
	ERROR_CLOSING_FILE
} status_t;

int main(void) {

	FILE *outfile;
	status_t st;

	/*
		Modos de apertura r w a, t b
		read
		write
		append
	*/

	outfile = fopen("concat.txt", "at");
	if(outfile == NULL) {
		fprintf(stderr,"Error abriendo archivo\n");
		st = ERROR_OPENING_FILE;
		return st;
	}

	fprintf(outfile, "Appending text \n");

	if(fclose(outfile) == EOF) {
		st = ERROR_CLOSING_FILE;
		return st;	
	}

	return EXIT_SUCCESS;

}
