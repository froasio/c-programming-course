#include <stdio.h>
#include <stdlib.h>

void print_array(int v[], size_t l);
int linear_search(int v[], size_t l, int target);
int linear_search_recursive(int v[], size_t l, int target);
int _linear_search_recursive(int v[], size_t i, size_t j, int target);
int binary_search(int v[], size_t l, int target);
int binary_search_recursive(int v[], size_t l, int target);
int _binary_search_recursive(int v[], size_t i, size_t j, int target);

int main(void) {

	int b[8] = {1,2,3,4,5,6,7,8};
	int pos;
	print_array(b,8);

	pos = linear_search_recursive(b,8,4);
	printf("%d\n", pos);

	return EXIT_SUCCESS;

}

int binary_search_recursive(int v[], size_t l, int target) {

	return _binary_search_recursive(v,0,l-1,target);

}

int _binary_search_recursive(int v[], size_t i, size_t j, int target) {

	size_t m;

	if(i > j)
		return -1;

	m = i + (j-i)/2;

	if(target > v[m])
		return _binary_search_recursive(v,m+1,j,target);
	
	if(target < v[m])
		return _binary_search_recursive(v,i,m-1,target);

	return m;
}

int binary_search(int v[], size_t l, int target) {

	size_t i, j, m;
	i = 0;
	j = l - 1;

	while(i < j){

		m = i + (j-i)/2;

		if(v[m] == target) {
			return m;
		} else if (target < v[m]) {
			j = m - 1;
		} else {
			i = m + 1;
		}

	}
	return -1;

}

int linear_search(int v[], size_t l, int target) {

	size_t i;
	for(i = 0; i < l; i++){
		if(v[i] == target) {
			return i;
		}
	}
	return -1;
}

int linear_search_recursive(int v[], size_t l, int target) {
	return _linear_search_recursive(v,0,l-1,target);
}

int _linear_search_recursive(int v[], size_t i, size_t j, int target) {

	if(i > j)
		return -1;

	if(v[i] == target)
		return i;

	return _linear_search_recursive(v,i+1,j,target);

}

void print_array(int v[], size_t l) {
	size_t i;
	for(i = 0; i < l; i++) {
		printf("%d ", v[i]);
	}
	putchar('\n');
}
