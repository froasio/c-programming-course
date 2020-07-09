#include <stdio.h>
#define SIMBOLO_PESOS_ARG "ARS"
#define SIMBOLO_DOLARES "USD"
#define CONVERSION_DOLARES_A_PESOS 58

int main(void) {

	double valor_pesos_argentinos;
	double valor_dolares;

	do {

		printf("Ingrese el precio en %s: \n", SIMBOLO_DOLARES);
		scanf("%lf", &valor_dolares);

		if(valor_dolares < 0) {
			fprintf(stderr, "El valor ingresado no puede ser negativo\n");
		}

	} while (valor_dolares < 0);
	
	valor_pesos_argentinos = valor_dolares * CONVERSION_DOLARES_A_PESOS;

	printf("Valor en %s: %.2f \n", SIMBOLO_PESOS_ARG, valor_pesos_argentinos);
	return 0;

}
