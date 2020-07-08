#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int espec(int x);
int espec_(int acum, int x);

int main(void) {

	printf("%d\n", espec(4911234));
	return 0;
}

int espec(int x) {
	return espec_(0,x);
}

int espec_(int acum, int x){

	if(x < 10)
		return acum + x;
	
	return espec_(10*(acum+x%10), x/10);
}