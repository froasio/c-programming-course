#include <stdio.h>
#include <stdlib.h>

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_OUT_OF_MEMORY
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

status_t clone_record(const record_t *r, record_t **cr);
status_t delete_record(record_t **r);
status_t print_record(const record_t *);
status_t print_angle(const angle_t *a);

int main(void) {

	record_t r;
	record_t *cr;
	status_t st;

	r.latitude = (angle_t*) malloc(sizeof(angle_t));
	/*Validar*/
	r.longitude = (angle_t*) malloc(sizeof(angle_t));
	/*Validar*/

	r.id = 1;
	(*(r.latitude)).degrees = 10;
	(r.latitude)->minutes = 11;
	(r.latitude)->seconds = 12;

	(r.longitude)->degrees = 20;
	(r.longitude)->minutes = 21;
	(r.longitude)->seconds = 22;

	st = clone_record(&r, &cr);
	if(st != OK) {
		free(r.latitude);
		free(r.longitude);
		return st;
	}

	print_record(cr);
	
	free(r.latitude);
	free(r.longitude);
	delete_record(&cr);

	return EXIT_SUCCESS;

}

status_t delete_record(record_t **r){
	free((*r)->latitude);
	(*r)->latitude = NULL;
	free((*r)->longitude);
	(*r)->longitude = NULL;
	free(*r);
	*r = NULL;
	return OK;
}

status_t clone_record(const record_t *r, record_t **cr) {

	if(r == NULL || cr == NULL)
		return ERROR_NULL_POINTER;
	
	*cr = (record_t*) malloc(sizeof(record_t));
	if(*cr == NULL)
		return ERROR_OUT_OF_MEMORY;

	/*Armar funcion de clonación de angle_t*/
	(*cr)->latitude = (angle_t*) malloc(sizeof(angle_t));
	if((*cr)->latitude == NULL) {
		free(*cr);
		return ERROR_OUT_OF_MEMORY;
	}
	
	(*cr)->longitude = (angle_t*) malloc(sizeof(angle_t));
	if((*cr)->longitude == NULL) {
		free(*cr);
		free((*cr)->latitude);
		return ERROR_OUT_OF_MEMORY;
	}

	(*cr)->id = r->id;
	((*cr)->latitude)->degrees = r->latitude->degrees;
	((*cr)->latitude)->minutes = r->latitude->minutes;
	((*cr)->latitude)->seconds = r->latitude->seconds;

	((*cr)->longitude)->degrees = r->longitude->degrees;
	((*cr)->longitude)->minutes = r->longitude->minutes;
	((*cr)->longitude)->seconds = r->longitude->seconds;	

	return OK;
	
}

status_t print_record(const record_t *r) {

	printf("Id: %lu\n", r->id);
	printf("Latitude: \n");
	print_angle(r->latitude);
	printf("Longitude: \n");
	print_angle(r->longitude);

	return OK;
}

status_t print_angle(const angle_t *a) {
	printf("%d %d %d\n", a->degrees, a->minutes, a->seconds);
	return OK;
}