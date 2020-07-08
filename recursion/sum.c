#include <stdio.h>
#include <math.h>
#include <stdlib.h>

size_t sum_n(size_t n);
size_t sum_n_tr(size_t n);
size_t sum_n_tr_wrapper(size_t n, size_t acum);

int main(void) {

	printf("%lu\n", sum_n_tr(10));
	return 0;
}

size_t sum_n(size_t n){
	if( n < 1)
		return 0;
	return n + sum_n(n-1);
}

size_t sum_n_tr(size_t n){
	return sum_n_tr_wrapper(n,0);
}

size_t sum_n_tr_wrapper(size_t n, size_t acum){
	if(n < 1)
		return acum;
	return sum_n_tr_wrapper(n-1, acum + n);
}