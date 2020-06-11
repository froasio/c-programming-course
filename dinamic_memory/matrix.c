#include <stdio.h>
#include <stdlib.h>
#define COLS 3
#define ROWS 3

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_OUT_OF_MEMORY
} status_t;

status_t delete_matrix (double **, size_t n_rows, size_t n_cols);
status_t delete_matrix_ (double ***, size_t n_rows, size_t n_cols);
status_t create_matrix (size_t n_rows, size_t n_cols, double ***);


int main(void) {

	double **m;
	status_t st;
	size_t i,j;

	st = create_matrix(ROWS, COLS, &m);
	if(st != OK) {
		/*Informar un error por stdout en función del status*/
		return st;
	}

	for(i = 0; i < ROWS; i++){
		for(j = 0; j < COLS; j++) {
			printf("%.2f ", m[i][j]);
		}
		putchar('\n');
	}
		
	delete_matrix_(&m, ROWS, COLS);
	return 0;
}

status_t delete_matrix (double ** m, size_t n_rows, size_t n_cols) {

	size_t i;
	if(m == NULL)
		return ERROR_NULL_POINTER;

	for(i = 0; i < n_rows; i++) {
		free(m[i]);
	}
	free(m);
	return OK;

}

status_t delete_matrix_ (double *** m, size_t n_rows, size_t n_cols) {
	
	size_t i;
	if(m == NULL)
		return ERROR_NULL_POINTER;

	for(i = 0; i < n_rows; i++) {
		free((*m)[i]);
		(*m)[i] = NULL;	
	}

	free(*m);
	*m = NULL;

	return OK;

}

status_t create_matrix (size_t n_rows, size_t n_cols, double ***m) {

	size_t i;
	
	if(m == NULL)
		return ERROR_NULL_POINTER;

	*m = (double**) malloc(sizeof(double*) * n_rows);
	if(*m == NULL)
		return ERROR_OUT_OF_MEMORY;

	for(i = 0; i < n_cols; i++) {
		(*m)[i] = (double*)calloc(n_cols, sizeof(double));
		if((*m)[i] == NULL) {
			delete_matrix_(m, i, n_cols);
			return ERROR_OUT_OF_MEMORY;
		}
	}
	
	return OK;
}