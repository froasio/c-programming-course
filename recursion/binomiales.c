#include <stdio.h>
#include <stdlib.h>

int C(int n, int k, int l);

int main(void) {

	printf("C(6,4): %d \n", C(6,4,0));

	return EXIT_SUCCESS;
}

int C(int n, int k, int level) {

	if(k > n)
		return 0;
	
	if(k == 0 || n == k) {
		printf("n:%d, k:%d, l:%d\n",n,k,level);
		return 1;
	}
	
	printf("n:%d, k:%d, l:%d\n",n,k,level);
	return C(n-1, k, level+1) + C(n-1,k-1, level+1);

}
