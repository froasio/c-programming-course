#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void) {

	size_t i;
	int v[N] = {50,-1,22,10,21};
	size_t i_min;

	i_min = 0;

	for(i=1; i<N; i++) {

		if(v[i] < v[i_min]) {
			i_min = i;
		}

	}

	printf("Min: %d Pos: %lu\n", v[i_min], i_min);
	return EXIT_SUCCESS; 

}
