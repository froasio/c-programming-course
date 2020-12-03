#include <stdio.h>
#include <ctype.h>

int main(void) {

	char s[10] = "hola 2020";
	char t[10];
	size_t i;
	char *p, *pt, *ps;

	for(i = 0; s[i]; i++){
		s[i] = toupper(s[i]);
		printf("%p \n", (void*)&(s[i]));
	}

	puts(s);

	for(p = s; *p; p++){
		*p = tolower(*p);
		printf("%p \n", (void*)p);
	}	
	
	puts(s);

	/*for(i = 0; (t[i] = s[i]) != '\0'; i++);*/
	for(pt = t, ps = s; (*pt = *ps) != '\0'; pt++, ps++);

	puts(t);

	return 0;

}