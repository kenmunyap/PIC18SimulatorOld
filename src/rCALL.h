#ifndef	__RCALL_H__
#define	__RCALL_H__

#define WREG  0xf8b
#define TOSU   0xFFF
#define TOSH   0xFFE
#define TOSL   0xFFD
#define STKPTR 0xFFC

extern int PIC18Stack[];
extern unsigned char FSR[];
extern int PC;

int  rcall(Bytecode *code);

#endif	// __RCALL_H__