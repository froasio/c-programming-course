#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(void) {

	size_t col, row, i;
	int matrix[N][N];
	int traza;
	int valor_ingresado;

	for(row = 0; row < N; row++) {

		for(col = 0; col < N; col++) {

			printf("Ingrese el valor de la fila %lu columna %lu: \n", row+1, col+1);
			scanf("%i", &valor_ingresado);
			matrix[row][col] = valor_ingresado;

		}

	}

	traza = 0;

	for(i = 0; i < N; i++) {
		traza += matrix[i][i];
	}

	printf("Traza: %d\n", traza);

	return EXIT_SUCCESS;
}
