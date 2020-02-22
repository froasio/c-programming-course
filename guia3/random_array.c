#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void) {

	size_t i;
	double v[N];

	srand(time(NULL));

	for(i=0; i<N; i++) {
		v[i] = rand() / (double) RAND_MAX;
	}

	for(i=0; i<N; i++) {
		printf("%lf\n", v[i]);
	}

	return EXIT_SUCCESS;
}
