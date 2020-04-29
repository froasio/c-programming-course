#include <stdio.h>

int main(void) {

	size_t i;

	for (i = 0; i < 10; i++) {
		if (i == 4) {
			break;
		}
		printf("%lu\n", i);
	}
	return 0;
}

