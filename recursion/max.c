#include <stdio.h>
#include <stdlib.h>

int max_classic(int v[], size_t l);
int max_tr(int v[], size_t l);
int _max_tr(int v[], size_t l, int max);
int max_dq(int v[], size_t l);

int main(void) {

	int v[5] = {1,2,3,4,5};

	printf("%d\n", max_dq(v, 5));
	
	return EXIT_SUCCESS;
}

int max_classic(int v[], size_t l) {
	int max_next;

	if(l == 1)
		return v[0];
	
	max_next = max_classic(v+1, l-1);
	
	return max_next > v[0] ? max_next : v[0];

}

int max_tr(int v[], size_t l) {
	return _max_tr(v, l, v[0]);
}

int _max_tr(int v[], size_t l, int max) {

	if(l == 1)
		return v[0];
	
	if(v[0] > max)
		max = v[0];

	return _max_tr(v+1, l-1, max);

}

int max_dq(int v[], size_t l) {
	int max_l, max_r;

	if(l == 1)
		return v[0];
	
	max_l = max_dq(v,l/2);
	max_r = max_dq(&(v[l/2]),l-l/2);

	return max_l > max_r ? max_l : max_r;

}