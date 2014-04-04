#ifndef	__MULLW_H__
#define	__MULLW_H__


#define WREG   0xFE8

#define PRODH 0xFF4

#define PRODL 0xFF3

extern unsigned char FSR[];

int  mullw(Bytecode *code);

#endif	// __MULLW_H__