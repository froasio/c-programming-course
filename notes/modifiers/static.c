#include <stdio.h> 

int counter() {
  int i = 0;
  i++;
  return i;
}

int static_counter() {
  static int i = 0;
  i++;
  return i;
}

int main(void) {

  size_t i;

  for(i = 0; i < 5; i++) {
    printf("%d ", counter());
  }

  putchar('\n');

  for(i = 0; i < 5; i++) {
    printf("%d ", static_counter());
  }

  putchar('\n');

  return 0;
}