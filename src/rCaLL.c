#include <stdio.h>
#include "Bytecode.h"
#include "rCALL.h"
#include "CException.h"

unsigned char FSR[0x1000];
int PC;
void  rcall(Bytecode *code) {
		int value;
		int temp0 = 0b111110000000000000000;
		int temp1 = 0b000001111111100000000;
		int temp2 = 0b000000000000011111111;
	
	if(code->operand1<=-1028 || code->operand1 >= 1027){
			
			value = PC; 
			FSR[TOSU] = ((value & temp0)>>16); 
			FSR[TOSH] = ((value & temp1)>>8); 
			FSR[TOSL] = (value & temp2);
		
			PC = PC + 2;

	}else{
		Throw(op_error);
	}
}

			