#include <stdio.h>
#include "Bytecode.h"
#include "iOR.h"


unsigned char FSR[0x1000];

void  iorwf(Bytecode *code) {
		
		if(code->operand2 == 0){
			if(code->operand3 == 0){
			FSR[WREG] = FSR[code->operand1]^FSR[WREG];
			}
			else{
			FSR[WREG] = FSR[(FSR[BSR]<<8)+code->operand1]^FSR[WREG];
			}	
		}
		else{
			if(code->operand3 == 0){
			FSR[code->operand1] = FSR[code->operand1]^FSR[WREG];
			}
			else{
			FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^FSR[WREG];
			}
		}
		
}	
	

			
			
		
		
		
		
		
		
	

	

	
