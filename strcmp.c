#include <stdio.h>

int main(void) {

	char s[] = "chola";
	char t[] = "chau";
	size_t i = 0;
	int cmp;

	i = 0;
	while(s[i] == t[i] && s[i]){
		i++;
	}

	cmp = s[i] - t[i];

	printf("%d\n", cmp);
	return 0;
}
