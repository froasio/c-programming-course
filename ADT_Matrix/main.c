#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double ** data;
	size_t rows, cols;
} ADT_Matrix_t;

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_NO_MEMORY,
	ERROR_OUT_OF_RANGE
} status_t;

status_t ADT_Matrix_new(size_t rows, size_t cols, ADT_Matrix_t **m);
status_t ADT_Matrix_delete(ADT_Matrix_t **m);
void ADT_Matrix_print(ADT_Matrix_t *m);
status_t ADT_Matrix_set_element(ADT_Matrix_t *m, size_t i, size_t j, double d);
status_t ADT_Matrix_transpose(ADT_Matrix_t **m);

int main(void) {

	ADT_Matrix_t *m;
	status_t st;

	st = ADT_Matrix_new(3,2, &m);
	/* Validar */

	ADT_Matrix_set_element(m,0,0,1.0);
	ADT_Matrix_set_element(m,0,1,2.0);
	ADT_Matrix_set_element(m,1,0,3.0);
	ADT_Matrix_set_element(m,1,1,4.0);
	ADT_Matrix_set_element(m,2,0,5.0);
	ADT_Matrix_set_element(m,2,1,6.0);

	ADT_Matrix_print(m);

	ADT_Matrix_transpose(&m);

	ADT_Matrix_print(m);
	
	st = ADT_Matrix_delete(&m);
	/* Validar */

	return EXIT_SUCCESS;

}

status_t ADT_Matrix_new(size_t rows, size_t cols, ADT_Matrix_t **m){
	size_t i;

	if(m == NULL)
		return ERROR_NULL_POINTER;

	if((*m = (ADT_Matrix_t*)malloc(sizeof(ADT_Matrix_t))) == NULL)
		return ERROR_NO_MEMORY;

	if(((*m)->data = (double**) malloc(rows * sizeof(double*))) == NULL) {
		free(*m);
		*m = NULL;
		return ERROR_NO_MEMORY;
	}

	(*m)->rows = 0;
	(*m)->cols = cols;

	for(i = 0; i < rows; i++) {

		if(((*m)->data[i] = (double *)calloc(cols, sizeof(double))) == NULL) {
			ADT_Matrix_delete(m);
			return ERROR_NO_MEMORY;
		}
		(*m)->rows++;
	}

	return OK;
}

status_t ADT_Matrix_delete(ADT_Matrix_t **m){

	size_t i;

	if(m == NULL)
		return ERROR_NULL_POINTER;

	for(i = 0; i < (*m)->rows; i++){
		free((*m)->data[i]);
		(*m)->data[i] = NULL;
	}

	free((*m)->data);
	(*m)->data = NULL;

	free(*m);
	*m = NULL;

	return OK;
}

void ADT_Matrix_print(ADT_Matrix_t *m){
	
	size_t i,j;

	printf("%lu x %lu\n", m->rows, m->cols);

	for(i = 0; i < m->rows; i++) {
		for(j = 0; j < m->cols; j++) {
			printf("%.2f ", m->data[i][j]);
		}
		putchar('\n');
	}
}

status_t ADT_Matrix_set_element(ADT_Matrix_t *m, size_t i, size_t j,
								 double d) {

	if(m == NULL)
		return ERROR_NULL_POINTER;

	if(i > m->rows - 1 || j > m->cols - 1) {
		return ERROR_OUT_OF_RANGE;
	}

	m->data[i][j] = d;
	return OK;
}

status_t ADT_Matrix_transpose(ADT_Matrix_t **m) {

	ADT_Matrix_t *mt;
	status_t st;
	size_t i,j;

	if(m == NULL)
		return ERROR_NULL_POINTER;

	if((st = ADT_Matrix_new((*m)->cols, (*m)->rows, &mt)) != OK) {
		return st;
	}

	for(i = 0; i < (*m)->rows; i++) {
		for(j = 0; j < (*m)->cols; j++) {
			mt->data[j][i] = (*m)->data[i][j];
		}
	}

	ADT_Matrix_delete(m);
	*m = mt;
	return OK;

} 


