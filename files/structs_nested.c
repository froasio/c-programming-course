#include <stdio.h>
#include <stdlib.h>
#define IN_FILE "infile.b"
#define OUT_FILE "outfile.csv"
#define DELIMITER ','

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_OUT_OF_MEMORY,
	ERROR_OPENING_FILE,
	ERROR_CLOSING_FILE
} status_t;

typedef struct {
	int degrees;
	unsigned int minutes;
	unsigned int seconds;
} angle_t;

typedef struct {
	size_t id;
	angle_t latitude;
	angle_t longitude;
} record_t;

/*

id(size_t)|degrees(int)|minutes(uint)|seconds(uint)|degrees(int)|minutes(uint)|seconds(uint)
					| ---- latitude -------------------------| ---- longitude -------------------------|
*/

status_t show_error (status_t st);

int main(void) {

	record_t r;
	FILE *infile, *outfile;
	status_t st;

	infile = fopen(IN_FILE, "rb");
	if(infile == NULL) {
		st = ERROR_OPENING_FILE;
		show_error(st);
		return st;
	}
	
	outfile = fopen(OUT_FILE, "wt");
	if(outfile == NULL) {
		st = ERROR_OPENING_FILE;
		show_error(st);
		return st;
	}

	fread(&r, sizeof(record_t),1,infile);
	while(!feof(infile)) {
		
		fprintf(outfile,
		"%09lu%c %d%c %d%c %d%c %d%c %d%c %d\n",
		r.id,
		DELIMITER,
		r.latitude.degrees,
		DELIMITER,
		r.latitude.minutes,
		DELIMITER,
		r.latitude.seconds,
		DELIMITER,
		r.longitude.degrees,
		DELIMITER,
		r.longitude.minutes,
		DELIMITER,
		r.longitude.seconds
		);

		fread(&r, sizeof(record_t),1,infile);
	}

	fclose(infile);
	if(fclose(outfile) == EOF) {
		st = ERROR_CLOSING_FILE;
		show_error(st);
		return st;	
	}

	return EXIT_SUCCESS;

}

status_t show_error (status_t st) {
	return OK;
}
