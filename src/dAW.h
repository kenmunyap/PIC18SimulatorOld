#ifndef	__DAW_H__
#define	__DAW_H__

#define WREG  0xf8b
#define BSR   0xfE0
#define STATUS 0xfd8 
extern unsigned char FSR[];

int  daw(Bytecode *code);

#endif	// __DAW_H__