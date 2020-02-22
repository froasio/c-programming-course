#include <stdio.h>

int main(void) {

	int numero_ingresado, i;

	printf("Ingrese un numero entero positivo:\n");
	scanf("%d", &numero_ingresado);

	if(numero_ingresado < 1) {
		fprintf(stderr, "ERROR: Numero no positivo\n");
		return 1;
	}

	numero_ingresado = numero_ingresado % 2 ? 
						numero_ingresado - 2 : 
						numero_ingresado - 1;

	for(i = numero_ingresado; i > 0; i -= 2) {
		printf("%d \n", i);
	}	

	return 0;

}
