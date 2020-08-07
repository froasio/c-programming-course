#include <stdio.h>
#include <stdlib.h>

#define MAX_PRINTERS 2
#define MAX_USERS 3

typedef struct {
	size_t id;
	size_t age;
} user_t;

typedef enum {
	FORMAT_VERBOSE,
	FORMAT_CSV
}	format_t;

void print_verbose(user_t *u);
void print_csv(user_t *u);

void (*printers[MAX_PRINTERS])(user_t *) = {
	print_verbose,
	print_csv
};

int main(void) {

	user_t users[MAX_USERS] = {
		{1,20},
		{2,30},
		{3,40}	
	};

	size_t i;

	for(i = 0; i < MAX_USERS; i++) {
		printers[FORMAT_VERBOSE](&(users[i]));
	}

	return EXIT_SUCCESS;
}

void print_verbose(user_t *u) {
	printf("ID: %lu, AGE: %lu\n", u->id, u->age);
}

void print_csv(user_t *u){
		printf("%lu, %lu\n", u->id, u->age);
}