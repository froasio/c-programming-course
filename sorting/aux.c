#include <stdio.h>
#include <stdlib.h>

void print_array(int v[], size_t l);
void bubble_sort(int v[], size_t l);
void bubble_sort_param(int v[], size_t l, int (*cmp) (int a, int b));
int sort_order(int a, int b);
int reverse_order(int a, int b);
void swap(int *a, int *b);
void selection_sort(int v[], size_t l);
void insertion_sort(int v[], size_t l);

int main(void) {

	int b[8] = {8, 6, 10, 3, 1, 2, 5, 4};

	print_array(b,8);
	selection_sort(b,8);
	print_array(b,8);

	return EXIT_SUCCESS;

}

void selection_sort(int v[], size_t l) {

	size_t i, j, min;

	for(i = 0; i < l - 1; i++) {
		min = i;
		for(j = i; j < l; j++) {
			if(v[j] < v[min]) {
				min = j;
			}
		}
		swap(v+min, v+i);
	}

}

int sort_order(int a, int b) {
	return a - b;
}

int reverse_order(int a, int b) {
	return b - a;
}

void bubble_sort_param(int v[], size_t l, int (*cmp) (int a, int b)) {

	size_t i, j;

	for(i = 0; i < l - 1; i++) {
		for(j = 0; j < (l - 1 - i); j++) {
			if(cmp(v[j], v[j+1]) > 0) { 
				swap(v+j, v+j+1);
			}
		}
	}

}

void bubble_sort(int v[], size_t l) {

	size_t i, j;

	for(i = 0; i < l - 1; i++) {
		for(j = 0; j < (l - 1 - i); j++) {
			if(v[j] - v[j+1] > 0) { /* f(v_j, v_j+1)*/
				swap(v+j, v+j+1);
			}
		}
	}

}

void insertion_sort(int v[], size_t l) {
	size_t i,j;

	int index;
	for(i = 1; i < l; i++) {
		index = v[i];
		for(j = i; j > 0 && v[j-1] > index; j--) {
			v[j] = v[j-1];
		}
		v[j] = index;
	}

}

void swap(int *a, int *b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void print_array(int v[], size_t l) {
	size_t i;
	for(i = 0; i < l; i++) {
		printf("%d ", v[i]);
	}
	putchar('\n');
}
