#ifndef	__BYTECODE_H__
#define	__BYTECODE_H__

typedef enum 	{
					overRange,
					bsrRange,
					error_operand3,	
				} errorException;
				
typedef enum	{
					W = -2,
					F = -3,
					BANKED = -4,
					ACCESS = -5
				}SyntaxError;
				
typedef enum 	{
					BTG,
					MULLW,
					IORWF,
					XORWF,
					DCFSNZ,
				} Mnemonic;

typedef struct {
	Mnemonic	mnemonic;
	char *name;
} Instruction;

typedef struct {
	Instruction *instruction;
	int operand1;
	int operand2;
	int operand3;
} Bytecode;



#endif	// __BYTECODE_H__