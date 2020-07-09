#include <stdio.h>
#include <stdlib.h>
#define MACRO(a) a+1
#define MACRO_PROD(a) ((a)*2)
#define VALIDAR(c) ((c)! EOF && (c) != '\n')
#define GET_BIT(i,n) (((i)&(1<<(n))) ? 1:0)

int main(void) {
	
	int b;
	int c = 5;

	b = MACRO(c); /* c+1 */

	printf("%d \n", b);

	b = MACRO_PROD(1+5);

	printf("%d \n", b);

/* CUIDADO CON ESTO!
	c = getchar();
	if(VALIDAR(c)) {

	}

	if(VALIDAR(getchar())) {
		
	}
*/
	return EXIT_SUCCESS;
}
