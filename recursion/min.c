#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int find_min(int v[], size_t l);

int main(void) {

	int v[] = {1, 3 , -4 , 5};
	printf("%d\n", find_min(v,4));
	return 0;
}

int find_min(int v[], size_t l){

	int min_l, min_r;

	if(l <= 1)
		return *v;
	
	min_l = find_min(v,l/2);
	min_r = find_min(&(v[l/2]),l-l/2);

	return min_l < min_r ? min_l : min_r;
}