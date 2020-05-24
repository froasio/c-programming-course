#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 65

typedef unsigned char type_t;

void print_reg(unsigned char reg) {

  size_t i;
  printf(" _______________________________ \n");
  putchar('|');
  for(i = 0; i < sizeof(type_t) * 8; i++) {
    putchar(' ');
    putchar(reg & (1 << (sizeof(type_t) * 8 - 1 -i)) ? '1' : '0');
    putchar(' ');
    putchar('|');
  }
  printf("\n");
  printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n");  

}

int main (void){

    type_t v = 10;
    
    print_reg(v);
    printf("%X\n", v);
    printf("%o\n", v);

    return EXIT_SUCCESS;
}