#include <stdio.h>
#include "Bytecode.h"
#include "xOR.h"
#include "CException.h"

char FSR[0x1000];

void  xorwf(Bytecode *code) {
		
		if(code->operand1 <= 0 || code->operand1 >= 255){
				Throw(overRange);
		}
		else{	
		if(code->operand2 == 0){
			if(code->operand3 == 0){
			FSR[WREG] = ~(FSR[code->operand1]^FSR[WREG]);
			}
			else{
			FSR[WREG] = ~((FSR[(FSR[BSR]<<8)+code->operand1])^FSR[WREG]);
			}
		}
		else{
			if(code->operand3 == 0){
			FSR[code->operand1]= ~(FSR[code->operand1]^FSR[WREG]);
			}
			else{
				if(FSR[BSR]>15){
						Throw(bsrRange);
				}
				else{
				FSR[code->operand1]= ~((FSR[(FSR[BSR]<<8)+code->operand1])^FSR[WREG]);
				}
		}
	}
}
		
		
	
		
			 	
			
	
	
			
}	
		
		
		
		
	
