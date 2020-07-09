#include <stdio.h>

int main(void) {

	size_t i;

	for (i = 0; i < 10; i++) {
		if (i == 4) {
			break;
		}
		printf("%lu \n", i);
	}
  
  
  puts("-----------");

	for (i = 0; i < 10; i++) {
		if (i == 4) {
			continue;
		}
		printf("%lu\n", i);
	}

  
  puts("-----------");

	i = 0;
	while (i < 10) {
		if (i == 4) {
	    	break;
		}
    printf("%lu \n", i);
		i++;
	}

  puts("-----------");

	i = 0;
	while (i < 10) {
    if (i == 4) {
        i++;
	    	continue;
		}
    printf("%lu \n", i);
    i++;
	}
  
	return 0;
}

