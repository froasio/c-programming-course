#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 7
/*

[1,2,3,7,1,2,3]

XOR
0 0 0
0 1 1
1 0 1
1 1 0

7 ^ 7 = 0

B
111 
111
---
000

*/

int find_unique(int v[], size_t l);

int main(void) {

	int v[MAX_SIZE] = {1,2,3,1,1,2,3};

	printf("%d \n", find_unique(v, MAX_SIZE));

	return EXIT_SUCCESS;

}

int find_unique(int v[], size_t l) {

	int unique = 0;
	size_t i;

	for(i=0 ; i < l; i++) {
		unique ^= v[i]; 
	}

	return unique;
}

