#include <stdio.h>
#define N 10

int main(void) {

	size_t i;
	int v[N];

	int suma_total;

	for(i=0; i<N; i++) {

		printf("Ingrese el numero %lu \n", i);
		scanf("%d", &(v[i])); /* Validar */

	}

	suma_total = 0;

	for(i=0; i<N; i++) {
		suma_total += v[i];
		printf("%d\n", v[i]);
	}

	printf("Suma total: %d\n", suma_total);
	return 0;
}
