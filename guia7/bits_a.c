a)
typedef enum {LO = 0, HI = 1} bit_t;
typedef enum {TRUE, FALSE} bool_t;

b)

#define MASK_TXCIE 0x40

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