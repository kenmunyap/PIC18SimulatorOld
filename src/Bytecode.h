#ifndef	__BYTECODE_H__
#define	__BYTECODE_H__

typedef enum 	{
					overRange,
					bsrRange,
					error_operand3,	
					op_error,
					op_2error,
					op_3error,
					fsr_wreg
				} errorException;
				
typedef enum	{
					W = -2,
					F = -3,
					BANKED = -4,
					ACCESS = -5
				}SyntaxError;
				
typedef enum 	{
					BTG,   //no status affect 
					MULLW,//done no status affect
					IORWF,//done status affect
					XORWF,//done status affect
					DCFSNZ,//done no status affect
					RRCF,//done status affect
					DAW,//done status
					POP,//done
					RCALL,//done
					TBLRD_post_increment,
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
	int absoluteAddress;
} Bytecode;



#endif	// __BYTECODE_H__