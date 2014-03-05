#ifndef	__XOR_WF_H__
#define	__XOR_WF_H__

#define WREG  0xf8b
#define BSR   0xfE0

extern char FSR[];

void  xorwf(Bytecode *code);

#endif	// __XOR_WF_H__