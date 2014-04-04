#ifndef	__Bit_Toggle_H__
#define	__Bit_Toggle_H__

#define WREG  0xf8b
#define BSR   0xfE0
extern unsigned char FSR[];

int  bitToggle(Bytecode *code);

#endif	// __Bit_Toggle_H__