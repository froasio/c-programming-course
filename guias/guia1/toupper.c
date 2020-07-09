#include <stdio.h>
#include <ctype.h>

int main(void) {

	int c;

	while( (c = getchar()) != EOF ) {

		putchar(toupper(c));

	} 

	return 0;

}
