#ifndef	__IOR_WF_H__
#define	__IOR_WF_H__

#define WREG  0xf8b
#define BSR   0xfE0

extern unsigned char FSR[];

void  dcfsnz(Bytecode *code);

#endif	// __IOR_WF_H__