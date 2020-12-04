#include <stdio.h>
#include <stdlib.h>
#define MASK_BYTE 0xFF

/*
Escribir un fragmento de código/procedimiento que convierta un número entero sin signo (32
bits) a formato Big Endian, sobre un arreglo de 4 bytes. Imprimir por stdout las
representaciones de origen y de destino.
Ejemplo: el número 271590900 será codificado como:
x[0] = 0x10
x[1] = 0x30
x[2] = 0x25
x[3] = 0xF4 
*/

int main(void) {

	unsigned int n = 271590900; /*0x10 30 25 f4*/
	unsigned int nn = 0;
	unsigned char v[4];
	size_t i;
	
	/*

	v[0] = (n >> 24) & 0xFF;
	v[1] = (n >> 16) & 0xFF;
	v[2] = (n >> 8) & 0xFF;
	v[3] = (n >> 0) & 0xFF;

	0x00000010
	0x000000FF
	----------
	0x00000010
	
	0x00001030
	0x000000FF
	----------
	0x00000030	

	0x00103025
	0x000000FF
	----------
	0x00000025

	0x103025f4
	0x000000FF
	----------
	0x000000f4

	*/

	for(i = 0; i< sizeof(unsigned int) ;i++) {
		v[i] = ( n >> ( (sizeof(unsigned int)-1-i) * 8 ) ) & MASK_BYTE;
	}

	printf("%x \n", n);

	for(i = 0; i< sizeof(unsigned int) ;i++){
		printf("v[%lu]=0x%x \n",i,v[i]);
	}

	/* 
	
	nn = (v[0] << 24) | (v[1] << 16)| (v[2] << 8) | (v[3]);
	
	0x10 00 00 00
	0x00 30 00 00
	0x00 00 25 00
	0x00 00 00 F4
	-------------
	0x10 30 25 f4
	
	*/

	for(i = 0; i< sizeof(unsigned int) ;i++){
		nn |= v[i] << ((sizeof(unsigned int)-1-i) * 8 );
	}
	
	printf("%x \n", nn);

	return EXIT_SUCCESS;
}
