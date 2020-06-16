#include <stdio.h>
#include <stdlib.h>

char* itob(int n);

int main(void) {

	int i = 10;
	char *s;

	s = itob(i);
	if(s == NULL)
		return EXIT_FAILURE;
		
	puts(s);

	return EXIT_SUCCESS;
}

char* itob(int n) {
	char *s;
	size_t i;

	s = (char*) malloc(sizeof(char)*(sizeof(int)*8+1));
	if(s == NULL)
		return NULL;

	for(i = 0; i < sizeof(int) * 8; i++) {
		s[i] = n & (1 << (sizeof(int)*8 - i - 1))? '1' : '0';
	}
	s[i] = '\0';
	return s;
}
