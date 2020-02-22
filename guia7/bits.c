#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 65

typedef unsigned char type_t;

int main (void){

    type_t v = 10;
    size_t i;
    char s[MAX_SIZE];

    for(i = 0; i < sizeof(type_t) * 8; i++) {
        s[i] = v & (1 << (sizeof(type_t) * 8 - 1 -i)) ? '1' : '0';
    }
    s[i] = '\0';
    puts(s);
    printf("%X\n", v);
    printf("%o\n", v);

    return EXIT_SUCCESS;
}