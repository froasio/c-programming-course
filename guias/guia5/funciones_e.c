#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define M 20

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t left_trim(char s[]);
status_t right_trim(char s[]);
status_t trim(char s[]);

int is_char(char c, char t) {
  return c == t;
}

int main(void) {
    char s[M] = "....hola....";
    trim(s);
    puts(s);
    printf("L: %d \n", (int)strlen(s));
    return 0;
} 

status_t left_trim(char s[]) {
    size_t i;

    if(s == NULL)
      return ERROR_NULL_POINTER;

    for(i = 0; is_char('.', s[i]); i++);

    memmove(s, &(s[i]), strlen(s) - i + 1);
    
    return OK;
}

status_t right_trim(char s[]) {
    int i;

    if(s == NULL)
      return ERROR_NULL_POINTER;

    for(i = strlen(s) - 1; i >= 0 && is_char('.', s[i]); i--);
    s[i+1] = '\0';
    
    return OK;
}

status_t trim(char s[]) {
    status_t st;
    if(s == NULL)
      return ERROR_NULL_POINTER;
    
    st = right_trim(s);
    if(st != OK)
      return st;
    
    st = left_trim(s);
    if(st != OK)
      return st;

    return OK;
}