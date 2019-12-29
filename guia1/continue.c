#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void left_trim(char s[]) {
	
	size_t i;
	
	for(i = 0; isspace(s[i]); i++);
	/*for(i = 0; s[i] == ''; i++);*/

	memmove(s, &(s[i]), strlen(s) - i + 1);

}

void right_trim(char s[]) {

	int i;

	for(i = strlen(s) - 1; i >= 0 && isspace(s[i]); i--);
	s[i+1] = '\0';

}

void trim(char s[]) {
	left_trim(s);
	right_trim(s);
}

int main(void) {

	char s[] = "    hola    ";

	puts(s);

	trim(s);

	puts(s);

	return EXIT_SUCCESS;
}

