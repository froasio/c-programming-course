#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define M 10

void str_to_lwr(char s[]);

int main(void) {
    
    char s[M] = "HOLA!";

    str_to_lwr(s);

    puts(s);

    return 0;

} 

void str_to_lwr(char s[]){

    size_t i, l;
    
    l = strlen(s);

    for(i=0; i < l; i++) {
        s[i] = tolower(s[i]);
    }
    
}