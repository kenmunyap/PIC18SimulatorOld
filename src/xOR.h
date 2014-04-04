#ifndef	__XOR_WF_H__
#define	__XOR_WF_H__

#define WREG  0xf8b
#define BSR   0xfE0
#define STATUS 0xfd8 
extern unsigned char FSR[];

int  xorwf(Bytecode *code);

#endif	// __XOR_WF_H__