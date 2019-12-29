#include <stdio.h>
#include <stdlib.h>

void print_array(int v[], size_t l);
void bubble_sort(int v[], size_t l);
void bubble_sort_param(int v[], size_t l, int (*cmp) (int a, int b));
int sorted_order(int a, int b);
int reverse_order(int a, int b);
void selection_sort(int v[], size_t l);
void insertion_sort(int v[], size_t l);
void swap(int *a, int *b);

int main(void) {

	int b[8] = {8, 6, 10, 3, 1, 2, 5, 4};

	print_array(b,8);
	bubble_sort_param(b, 8, reverse_order);
	print_array(b,8);

	return EXIT_SUCCESS;

}

int sorted_order(int a, int b) {
	return a - b;
}

int reverse_order(int a, int b) {
	return b - a;
}

void bubble_sort_param(int v[], size_t l, int (*cmp) (int a, int b)){
	size_t i, j;
	size_t swaps;
	for(i = 0; i < (l - 1); i++) {
		swaps = 0;
		for(j = 0; j < (l - 1 - i); j++) {
			if(cmp(v[j], v[j+1]) > 0) {
				swap(&(v[j]), &(v[j+1]));
				swaps++;
			}
		}
		if (swaps == 0)
				break;
	}
}

void bubble_sort(int v[], size_t l) {
	size_t i, j;
	size_t swaps;
	for(i = 0; i < (l - 1); i++) {
		swaps = 0;
		for(j = 0; j < (l - 1 - i); j++) {
			if(v[j] > v[j+1]) {
				swap(&(v[j]), &(v[j+1]));
				swaps++;
			}
		}
		if (swaps == 0)
				break;
	}
}

void selection_sort(int v[], size_t l) {

	size_t i,j;
	int min;

	for(i = 0; i < l - 1; i++) {
		min = i;
		for(j = i + 1; j < l; j++) {
			if(v[j] < v[min])
				min = j;
		}
		swap(&(v[i]), &(v[min]));
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


