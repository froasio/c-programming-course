#include <stdio.h>

void f1() {
  printf("f1 \n");
}

static void f2() {
  printf("f2 \n");
}

void f3() {
  f2();
}