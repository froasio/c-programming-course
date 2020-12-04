#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 65

typedef unsigned char reg_t;

void print_reg(reg_t reg) {

  size_t i;
  printf(" _______________________________ \n");
  putchar('|');
  for(i = 0; i < sizeof(reg_t) * 8; i++) {
    putchar(' ');
    putchar(reg & (1 << ((sizeof(reg_t) * 8) - 1 - i)) ? '1' : '0');
    putchar(' ');
    putchar('|');
  }
  printf("\n");
  printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n");  

}

int main (void){

		/*
			000001
			010000
		*/
    reg_t v1 = 0xAA;
		reg_t v2 = 1 << 4; 
    
		print_reg(v1);
		print_reg(v2);
    print_reg(v1 ^ v2);

    return EXIT_SUCCESS;

}