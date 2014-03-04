#ifndef	__MULLW_H__
#define	__MULLW_H__

#define WREG  0xf8b
#define PRODH 0xFF4
#define PRODL 0xFF3
extern char FSR[];

void  mullw(Bytecode *code);

#endif	// __MULLW_H__