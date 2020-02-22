#include <stdio.h>
#include <string.h>

int main(void) {

	char s[] = "hola como federico como estas?";
	char t[] = "chau";
	char *x;

	x = strstr(s,t);

	if(x == NULL) {
		printf("No encontre t en s\n");
		return 0;
	}

	putchar(*x);
	putchar('\0');
	puts(x);

	return 0;

}
