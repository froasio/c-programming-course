#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 65

typedef unsigned char type_t;

void print_binary(type_t v);

int main (void){

    type_t v = 100;
    
		print_binary(v);
    printf("%X\n", v);
    printf("%o\n", v);

    return EXIT_SUCCESS;
}

void print_binary(type_t v) {
	char s[MAX_SIZE];
	size_t i;
	for(i = 0; i < sizeof(type_t) * 8; i++) {
				/*

				0111 0111 0111 0111
				1000 0100 0010 0001 => 1 << (sizeof(type_t) * 8 - 1 - i)
				---- ---- ---- ----
				0000 0100 0010 0001
				
				'0'  '1'  '1'  '1'
				*/

        s[i] = v & (1 << (sizeof(type_t) * 8 - 1 -i)) ? '1' : '0';

    }
    s[i] = '\0';
	  puts(s);

}
