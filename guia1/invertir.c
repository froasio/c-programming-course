#include <stdio.h>

int main(void) {

	size_t x = 299;
	size_t y = 0;

	while(x != 0) {

		y = x % 10 + y * 10;
		x /= 10;

	}

	printf("%lu\n", y);
	return 0;
}
