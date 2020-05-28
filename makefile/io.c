#include <stdio.h>
#include "io.h"

void read_data(int* a, int* b) {
	scanf("%i %i", a, b);
}

void write_data(int a) {
	printf("Suma total: %d\n", a);
}
