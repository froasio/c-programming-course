#include <stdio.h>
#define SUM_ERROR 1E-9

int main(void) {

	int N = 1;
	double e = 1;
	double invf = 1;

	while(invf > SUM_ERROR) {

		invf /= N; /* invf = 1/N * invf */
		e += invf; /* e = e + invf */
		N++;
	}

	printf("El valor de e es: %.5f\n", e);
	printf("El valor de N es: %d\n", N);

	return 0;

}
