#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double real;
	double imag;
} complex_t;

complex_t* clone_complex_array(const complex_t *cc, size_t l);
void delete_complex_array(complex_t **cc);
complex_t *build_complex_array_from_strings(char **ss, size_t l);
void print_complex_array(const complex_t *cc, size_t l);

int main(int argc, char **argv) {

	complex_t *c;
	complex_t *cc;
	size_t len;

	if(argc == 1) {
		fprintf(stderr, "Argumentos insuficientes\n");
		return EXIT_FAILURE;
	}
	len = argc - 1;

	c = build_complex_array_from_strings(argv, argc);
	if(c == NULL) {
		fprintf(stderr, "Fallo en la creacion del arreglo\n");
		return EXIT_FAILURE;
	}

	print_complex_array(c, len);

	cc = clone_complex_array(c, len);
	if(cc == NULL) {
		delete_complex_array(&c);
		fprintf(stderr, "Fallo en la clonacion del arreglo\n");
		return EXIT_FAILURE;
	}

	print_complex_array(cc, len);
	delete_complex_array(&c);
	delete_complex_array(&cc);

	return EXIT_SUCCESS;

}

void print_complex_array(const complex_t *cc, size_t l) {
	
	size_t i;
	
	if(cc == NULL)
		return;

	for(i = 0; i < l; i++) {
		printf("(%f, %f) \n", cc[i].real, cc[i].imag);
	}

}

void delete_complex_array(complex_t **cc){
	
	if(cc == NULL)
		return;

	free(*cc);
	*cc = NULL;

}

complex_t *build_complex_array_from_strings(char **ss, size_t l) {

	complex_t *c;
	size_t i;
	char* tmp;

	if(ss == NULL || l == 0)
		return NULL;

	c = (complex_t*) malloc(l * sizeof(complex_t));
	if(c == NULL) {
		return NULL;
	}

	for(i = 1; i < l; i++) {
		c[i].imag = 0;
		c[i].real = strtod(ss[i], &tmp);
		if(*tmp){
			free(c);
			return NULL;
		}
	}
	return c;

}

complex_t* clone_complex_array(const complex_t *cc, size_t l) {

	size_t i;
	complex_t *c;

	c = (complex_t*)malloc(l*sizeof(complex_t));
	if(c == NULL)
		return NULL;

	for(i = 0; i < l; i++) {
		c[i].real = cc[i].real;
		c[i].imag = cc[i].imag;
	}

	return c;

}
