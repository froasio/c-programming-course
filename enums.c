#include <stdio.h>
#define MAXWELL_MANUFACTURER_ID 1
#define SONY_MANUFACTURER_ID 2
#define MAXWELL_NAMING "Maxwell Corporation"
#define SONY_NAMING "Sony Corporation"

typedef enum {
	MAXWELL_CORPORATION,
	SONY_CORPORATION	
} manufacturer_t;

int main(void) {

	int option;
	manufacturer_t manufacturer;

	printf("Ingrese el id del fabricante:\n");
	printf("%d - %s\n", MAXWELL_MANUFACTURER_ID, MAXWELL_NAMING);
	printf("%d - %s\n", SONY_MANUFACTURER_ID, SONY_NAMING);
	
	scanf("%d", &option); /* Validar */

	/*Traducción*/
	switch(option) {
		case MAXWELL_MANUFACTURER_ID:
			manufacturer = MAXWELL_CORPORATION;
			break;
		case SONY_MANUFACTURER_ID:
			manufacturer = SONY_CORPORATION;
			break;
		default:
			manufacturer = MAXWELL_CORPORATION;
	}

	/*Procesamiento*/

	switch(manufacturer) {
		case MAXWELL_CORPORATION:
			printf("%s\n", MAXWELL_NAMING);
			break;
		case SONY_CORPORATION:
			printf("%s\n", SONY_NAMING);
			break;
	}
	
	return 0;
}
