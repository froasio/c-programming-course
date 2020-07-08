#include <stdio.h>
#include <stdlib.h>

double exp_recursive(double x, size_t n);
double exp_recursive_wrapper(double x, size_t i, size_t n);

int main(void) {

	printf("%f\n", exp_recursive(1,10));
	return 0;
}

double exp_recursive(double x, size_t n){
	
	return exp_recursive_wrapper(x,1,n);

}

double exp_recursive_wrapper(double x, size_t i, size_t n){
	
	if(n == 0 || i == 0)
		return 1;
	if(i == n)
		return 1 + x / i;
	return 1 + (x * exp_recursive_wrapper(x, i + 1, n) / i);

}