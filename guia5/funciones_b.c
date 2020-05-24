#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define M 10

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t str_to_lwr(char s[]);
status_t str_to_lwr_pointers(char *s);

int main(void) {
    
    char s[M] = "HOLA!";

    if(str_to_lwr(s) != OK) {
      fprintf(stderr, "Error \n");
      return EXIT_FAILURE;
    }

    puts(s);

    return EXIT_SUCCESS;

} 

status_t str_to_lwr(char s[]){
    
    size_t i;

    if(s == NULL)
      return ERROR_NULL_POINTER;    
    
    for(i=0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
    return OK;
}

status_t str_to_lwr_pointers(char *s) {
  
  if(s == NULL)
      return ERROR_NULL_POINTER;

  for(; *s; s++)
    *s = tolower(*s);
  
  return OK;
}
