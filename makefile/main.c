#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "io.h"

int main(void) {
	int a, b, result;
	
	read_data(&a, &b);
	result = sum(a, b);
	write_data(result);

	return EXIT_SUCCESS;
}
