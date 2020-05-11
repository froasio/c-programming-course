#include <stdio.h>
#define N 3
#define USER_MSG "Ingrese el numero"
#define OUTPUT_MSG "Suma total:"

int main(void) {

	size_t i;
	int v[N];

	int suma_total;

	for(i=0; i<N; i++) {

		printf("%s %lu \n",USER_MSG, i);
		scanf("%d", &(v[i])); /* Validar */

	}

	suma_total = 0;

	for(i=0; i<N; i++) {
		suma_total += v[i];
		printf("%d\n", v[i]);
	}

	printf("%s %d\n", OUTPUT_MSG, suma_total);
	return 0;
}
