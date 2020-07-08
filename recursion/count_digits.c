#include <stdio.h>
#include <stdlib.h>

int count_digits(int x);

int main(void) {

	printf("Digits: %d \n", count_digits(123));

	return EXIT_SUCCESS;
}

int count_digits(int x) {

	if(x > -10 && x < 10){
		printf("x:%d\n",x);
		return 1;
	}

	printf("x:%d\n",x);
	return count_digits(x/10) + 1;

}
