#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

    size_t i;
    printf("argc: %d \n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("argv[%ld] = %s \n", i, argv[i]);
    }
    
    return EXIT_SUCCESS;
}