#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define M 20

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;
/*federoasio@gmail.com*/
status_t left_trim(char s[]);
status_t right_trim(char s[]);
status_t trim(char s[]);

int main(void) {
    char s[M] = "   hola   ";
    trim(s);
    puts(s);
    printf("L: %d", (int)strlen(s));
    return 0;
} 

status_t left_trim(char s[]) {
    size_t i;
    for(i = 0; isspace(s[i]); i++);
    memmove(s, &(s[i]), strlen(s) - i + 1);
    return OK;
}

status_t right_trim(char s[]) {
    int i;
    for(i = strlen(s) - 1; i >= 0 && isspace(s[i]); i--);
    s[i+1] = '\0';
    return OK;
}

status_t trim(char s[]) {
    right_trim(s);
    left_trim(s);
    return OK;
}