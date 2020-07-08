#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int pow_(int w, size_t k);

int main(void) {

	printf("%d\n", pow_(-2,3));
	return 0;
}

int pow_(int w, size_t k){

	if(k == 0)
		return 1;
	return w * pow_(w, k-1);
}