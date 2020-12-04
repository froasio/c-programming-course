#include <stdio.h>
#include <string.h>

#define M 10

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t string_reverse(char s[]);

int main(void) {
    char s[M] = "mundo";
    string_reverse(s);
    puts(s);
    return 0;
} 

status_t string_reverse(char s[]){
    size_t i, j;
    char aux;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
    return OK;
}