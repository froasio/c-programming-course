#include <stdio.h>
#include <stdlib.h>

typedef int (*comparator_t)(const void *, const void*);

int cmp_inorder_ints(const void * a, const void *b);
int cmp_inorder_floats(const void * a, const void *b);

void sort(void *v, size_t nitems, size_t size, comparator_t cmp);

void swap(void * a, void * b, size_t n);

int main(void) {

	size_t j;
	int i[] = {10,1,11,3,5,15};
	float f[] = {10.0,1.0,11.0,3.0,5.0,15.0};

	sort(i, 6, sizeof(int), cmp_inorder_ints);
	sort(f, 6, sizeof(float), cmp_inorder_floats);

	for(j = 0; j < 6 ; j++) {
		printf("%d %.1f \n", i[j], f[j]);
	}

	return EXIT_SUCCESS;

}

int cmp_inorder_ints(const void * a, const void *b) {
	int *aa = (int*) a;
	int *bb = (int*) b;
	return *bb > *aa;
}
int cmp_inorder_floats(const void * a, const void *b) {
	float *aa = (float*) a;
	float *bb = (float*) b;
	return *bb > *aa;
}

void sort(void *v, size_t l, size_t size, comparator_t cmp){

	size_t i, j;
	char *vv = (char*) v;

	for(i = 0; i < (l - 1); i++) {
		for(j = 0; j < (l - 1 - i); j++) {
			if(cmp(vv + size * j, vv + size * (j+1)) > 0) {
				swap(vv + size * j, vv + size * (j+1), size);
			}
		}
	}	

}

void swap(void * a, void * b, size_t n)
{
    unsigned char *p = a, *q = b, tmp;
		size_t i;
		
    for (i = 0; i != n; ++i)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}
