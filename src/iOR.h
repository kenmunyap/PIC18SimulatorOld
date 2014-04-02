#ifndef	__IOR_WF_H__
#define	__IOR_WF_H__

#define WREG  0xf8b
#define BSR   0xfE0
#define STATUS 0xfd8
extern unsigned char FSR[];

void  iorwf(Bytecode *code);

#endif	// __IOR_WF_H__