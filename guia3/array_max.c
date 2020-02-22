#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void) {

	size_t i;
	int v[N] = {2,-1,22,10,21};
	size_t i_max;

	i_max = 0;

	for(i=1; i<N; i++) {

		if(v[i] > v[i_max]) {
			i_max = i;
		}

	}

	printf("Max: %d Pos: %lu\n", v[i_max], i_max);
	return EXIT_SUCCESS;

}
