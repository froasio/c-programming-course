#include <stdio.h>
#include <stdlib.h>

#define N 2
#define P 3
#define M 2


int main(void) {

	size_t i,j,k;
	int m[N][P] = {{1,2,3}, {1,2,3}};
	int n[P][M] = {{1,2}, {1,2}, {1,2}};
	int r[N][M];

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			r[i][j] = 0;
			for(k = 0 ; k < P; k++) {
				r[i][j] += m[i][k] * n[k][j];
			}
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			printf("%d ", r[i][j]);
		}
		putchar('\n');
	}

	return EXIT_SUCCESS;

}
