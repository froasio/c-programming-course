#include <stdio.h>
#include <stdlib.h>


int main(void) {
	size_t i,j;
	int dos_vector[3][4] = { {1,2,3,4 }, { 5,6,7,8}, {9,10,11,12 } } ;
	int *dos_ptr;
	int (*ptr2vector)[4];

	ptr2vector = dos_vector;

	for(i=0; i < 3; i++, ptr2vector++){
		dos_ptr = *ptr2vector;
		for(j=0; j < 4; j++, dos_ptr++){
			printf("%d ", *dos_ptr);
		}
		putchar('\n');
	}

	return EXIT_SUCCESS;
}
