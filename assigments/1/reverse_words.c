#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

void reverse_words(char str[]);

int main(void) {

  char input[MAX];

  if(!fgets (input, MAX, stdin)) {
    fprintf(stderr, "Error reading input");
    return EXIT_FAILURE;
  }

  reverse_words(input);
  printf("%s", input);

	return EXIT_SUCCESS;
}

void reverse_words(char str[]) {
  /*Code*/
}
