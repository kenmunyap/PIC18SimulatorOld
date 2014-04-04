#ifndef	__TBLRD_POST_INCREMENT_H__
#define	__TBLRD_POST_INCREMENT_H__


#define WREG   0xFE8
#define TBLPTRU 0xFF8
#define TBLPTRH 0xFF7
#define TBLPTRL 0xFF6
#define TABLAT 0xFF5

extern int Table[];
extern unsigned char FSR[];


int tblrdpostincf(Bytecode *code);

#endif	// __TBLRD_POST_INCREMENT_H__