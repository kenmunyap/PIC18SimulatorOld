#ifndef	__RRCF_H__
#define	__RRCF_H__

#define WREG  0xf8b
#define BSR   0xfE0
#define STATUS 0xfd8 
extern unsigned char FSR[];

int  rrcf(Bytecode *code);

#endif	// __RRCF_H__