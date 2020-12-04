#include <stdio.h>
#define SUM_ERROR 10E-9 

/*
2,7182 8182 8 4 5904523
*/

int main(void) {

	int N = 1;
	double e = 1;
	double invf = 1;
	
	while(invf > SUM_ERROR) {
		invf /= N; /* invf =  invf / N */
		e += invf; /* e = e + invf */
		N++;
	}

	printf("El valor del error es: %.4f\n", invf);
	printf("El valor de e es: %.4f\n", e);
	printf("El valor de N es: %d\n", N);

	return 0;

}
