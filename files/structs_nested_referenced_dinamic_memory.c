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
	angle_t *latitude;
	angle_t *longitude;
} record_t;

status_t show_error (status_t st);
status_t create_record(record_t **cr);
status_t create_angle(angle_t **a);
status_t delete_record(record_t **r);


int main(void) {

	record_t *r;
	FILE *infile, *outfile;
	status_t st;

	st = create_record(&r);
	if(st != OK) {
		show_error(st);
		return st;
	}

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

	fread(&(r->id), sizeof(size_t),1,infile);
	fread(r->latitude, sizeof(angle_t),1,infile);
	fread(r->longitude, sizeof(angle_t),1,infile);
	while(!feof(infile)) {
		
		fprintf(outfile,
		"%09lu%c %d%c %d%c %d%c %d%c %d%c %d\n",
		r->id,
		DELIMITER,
		r->latitude->degrees,
		DELIMITER,
		r->latitude->minutes,
		DELIMITER,
		r->latitude->seconds,
		DELIMITER,
		r->longitude->degrees,
		DELIMITER,
		r->longitude->minutes,
		DELIMITER,
		r->longitude->seconds
		);

		fread(&(r->id), sizeof(size_t),1,infile);
		fread(r->latitude, sizeof(angle_t),1,infile);
		fread(r->longitude, sizeof(angle_t),1,infile);
	}

	fclose(infile);
	if(fclose(outfile) == EOF) {
		st = ERROR_CLOSING_FILE;
		show_error(st);
		return st;	
	}
	delete_record(&r);
	return EXIT_SUCCESS;

}

status_t show_error (status_t st) {
	return OK;
}

status_t create_record(record_t **r) {

	status_t st;

	if(r == NULL)
		return ERROR_NULL_POINTER;

	*r = (record_t*) malloc(sizeof(record_t));
	if(*r == NULL)
		return ERROR_OUT_OF_MEMORY;

	st = create_angle(&((*r)->latitude));
	if(st != OK) {
		free(*r);
		*r = NULL;
		return st;
	}

	st = create_angle(&((*r)->longitude));
	if(st != OK) {
		free(*r);
		*r = NULL;
		free((*r)->latitude);
		(*r)->latitude = NULL;
		return st;
	}

	return OK;
}

status_t create_angle(angle_t **a) {

	if(a == NULL)
		return ERROR_NULL_POINTER;
	
	*a = (angle_t*) malloc(sizeof(angle_t));
	if(*a == NULL)
		return ERROR_OUT_OF_MEMORY;
	
	return OK;

}

status_t delete_record(record_t **r){

	if(r == NULL)
		return ERROR_NULL_POINTER;

	free((*r)->latitude);
	(*r)->latitude = NULL;
	free((*r)->longitude);
	(*r)->longitude = NULL;
	free(*r);
	*r = NULL;
	return OK;

}