#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void) {
  size_t i,j;
	
	double v[N][N];

	srand(time(NULL));
	
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++){
  	  v[i][j] = rand() / (double) RAND_MAX;
    }
	}

	for(i=0; i<N; i++) {
    for(j=0; j<N; j++){
		  printf("%.3f ", v[i][j]);
    }
    putchar('\n');
	}

	return EXIT_SUCCESS;
}
