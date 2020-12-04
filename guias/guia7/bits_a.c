a)

typedef enum {LO = 0, HI = 1} bit_t;
typedef enum {TRUE, FALSE} bool_t;

b)

#define MASK_TXCIE 0x40 
/* 
x0xx xxxx
0100 0000 => 0x40 
0000 0000
*/

bit_t transmision_completa(unsigned char reg) {
    return (reg & MASK_TXCIE) ? HI : LO;
}

c)

unsigned char reg = 0xFF;
bit_t tx_sent;

tx_sent = tranmision_completa(reg);

d) 

void transmision_completa(unsigned char reg, bit_t *tx) {
    *tx = (reg & MASK_TXCIE) ? HI : LO;
}

unsigned char reg = 0xFF;
bit_t tx_sent;

tranmision_completa(reg, &tx_sent);

----------

12)
f(n, 3)
1001 1101
1111 0111
---------
1000 0001

typedef unsigned char
uchar set_bit(uchar byte, short linea) {
	return byte | (1 << linea);
}

uchar clear_bit(uchar byte, short linea){
	return byte & (~(1<<linea));
}
