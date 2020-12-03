#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

int sum_matrix(int m[][COLS], size_t rows, size_t cols);

int main(void) {

	int result;
	int m[ROWS][COLS] = {
		{1,2,3},
		{1,2,3},
		{1,2,3},
	};

	result = sum_matrix(m, ROWS, COLS);

	printf("%d \n", result);

	return EXIT_SUCCESS;

}

int sum_matrix(int m[][COLS], size_t rows, size_t cols) {

	size_t i,j;
	int sum;
	sum = 0;
	
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			sum+=m[i][j];
		}
	}
	return sum;
}

