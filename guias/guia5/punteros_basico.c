#include <stdio.h>

void swap(int *a, int *b);

int main(void) {

  int a,b;
  a = 5;
  b = 8;

  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);

	return 0;

}

void swap(int *c, int *d) {

  int aux;
  aux = *c;
  *c = *d;
  *d = aux;

}

