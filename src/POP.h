#ifndef	__POP_H__
#define	__POP_H__


#define WREG   0xFE8
#define TOSU   0xFFF
#define TOSH   0xFFE
#define TOSL   0xFFD
#define STKPTR 0xFFC

extern int PIC18Stack[];
extern unsigned char FSR[];
extern int PC;

void  pop(Bytecode *code);

#endif	// __POP_H__