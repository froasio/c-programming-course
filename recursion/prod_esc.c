#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prod_esc(int x[], int y[], int l);

int main(void) {

	int x[] = {2, 1};
	int y[] = {1, 2};
	printf("%d\n", prod_esc(x,y,2));
	return 0;
}

int prod_esc(int x[], int y[], int l){
	if(l == 0 ) return 0;
	return x[0]*y[0] + prod_esc(&(x[1]), &(y[1]), l - 1);
}
