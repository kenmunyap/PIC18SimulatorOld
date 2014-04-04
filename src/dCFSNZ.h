#ifndef	__DCFSNZ_H__
#define	__DCFSNZ_H__

#define WREG  0xf8b
#define BSR   0xfE0

extern unsigned char FSR[];

int  dcfsnz(Bytecode *code);

#endif	// __DCFSNZ_H__