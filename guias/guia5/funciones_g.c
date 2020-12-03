#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define DELIM ';'

void export_csv_matrix(int m[][COLS], size_t rows, size_t cols);

int main(void) {

	int m[ROWS][COLS] = {
		{1,2,3},
		{1,2,3},
		{1,2,3},
	};

	export_csv_matrix(m, ROWS, COLS);

	return EXIT_SUCCESS;

}

void export_csv_matrix(int m[][COLS], size_t rows, size_t cols){

	size_t i,j;
	char delim;

	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			printf("%d", m[i][j]);

			/* Operador ternario */
			delim = j < cols - 1 ? DELIM : '\n';
			
			printf("%c", delim);
		}
	}

}

