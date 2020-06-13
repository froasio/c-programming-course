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

status_t create_record(record_t **cr);
status_t create_angle(angle_t **a);
status_t clone_record(const record_t *r, record_t **cr);
status_t copy_angle(const angle_t *r, angle_t *cr);
status_t delete_record(record_t **r);
status_t print_record(const record_t *);
status_t print_angle(const angle_t *a);

int main(void) {

	record_t *r;
	record_t *cr;
	status_t st;

	st = create_record(&r);
	if(st != OK) {
		return st;
	}

	r->id = 1;
	r->latitude->degrees = 2;
	r->latitude->minutes = 3;
	r->latitude->seconds = 4;
	r->longitude->degrees = 5;
	r->longitude->minutes = 6;
	r->longitude->seconds = 7;

	st = clone_record(r, &cr);
	if(st != OK) {
		delete_record(&r);
		return st;
	}

	print_record(cr);
	
	delete_record(&r);
	delete_record(&cr);

	return EXIT_SUCCESS;

}

status_t copy_angle(const angle_t *r, angle_t *cr) {

	if(r == NULL || cr == NULL)
		return ERROR_NULL_POINTER;
	
	cr->seconds = r->seconds;
	cr->minutes = r->minutes;	
	cr->degrees = r->degrees;

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

status_t clone_record(const record_t *r, record_t **cr) {
	status_t st;

	if(r == NULL || cr == NULL)
		return ERROR_NULL_POINTER;
	
	st = create_record(cr);
	if(st != OK)
		return st;

	(*cr)->id = r->id;
	
	st = copy_angle(r->latitude, (*cr)->latitude);
	if(st != OK) {
		delete_record(cr);
		return st;
	}
	st = copy_angle(r->longitude, (*cr)->longitude);
	if(st != OK) {
		delete_record(cr);
		return st;
	}	

	return OK;
	
}

status_t print_record(const record_t *r) {

	if(r == NULL)
		return ERROR_NULL_POINTER;

	printf("Id: %lu\n", r->id);
	printf("Latitude: \n");
	print_angle(r->latitude);
	printf("Longitude: \n");
	print_angle(r->longitude);

	return OK;
}

status_t print_angle(const angle_t *a) {
	if(a == NULL)
		return ERROR_NULL_POINTER;

	printf("%d %d %d\n", a->degrees, a->minutes, a->seconds);
	return OK;
}