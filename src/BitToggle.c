#include <stdio.h>
#include "Bytecode.h"
#include "BitToggle.h"
#include "CException.h"

char unsigned FSR[0x1000];

int bitToggle(Bytecode *code) {

		/*
		*	Create a btg function to invert bit by bit 
		*	save the value in File Register or WREG
		*	Throw:op_2error range from -5 to 1
		*		  op_3error when having -2 -3 W or F
		*		  overRange when the range over from 0 to 255
		*	Input: BSR value,ACCESS value and FSR[code.operand1] value
		*	Return: value into BSR and ACCESS
		*/




	
	if(code->operand3 == -1){	
			code->operand3 = ACCESS;
	}
	if(code->operand3 == -2 || code->operand3 == W || code->operand3 == -3 || code->operand3 == F){
			Throw(error_operand3);
	}
	else if(code->operand1 <= 0x00 ){
				Throw(overRange);
	}
	else if( code->operand1 >= 0xff){
		printf("you have exceed range!!");
	}
	else{
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand3 == -5){
					if(code->operand1>=0x80){
						if(code->operand2 == 0){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000001;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==1){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000010;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==2){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000100;
						return (code->absoluteAddress)+1;
						}	
						else if(code->operand2==3){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00001000;
						return (code->absoluteAddress)+1;
						}	
						else if(code->operand2==4){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00010000;
						return (code->absoluteAddress)+1;
						}	
						else if(code->operand2==5){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00100000;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==6){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b01000000;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==7){
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b10000000;
						return (code->absoluteAddress)+1;
						}
						else{
						FSR[(0xf<<8)+code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000000;
						return (code->absoluteAddress)+1;
						}
					}
					else{
						if(code->operand2==0){
						FSR[code->operand1] = FSR[code->operand1]^0b00000001;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==1){
						FSR[code->operand1] = FSR[code->operand1]^0b00000010;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==2){
						FSR[code->operand1] = FSR[code->operand1]^0b00000100;
						return (code->absoluteAddress)+1;
						}	
						else if(code->operand2==3){
						FSR[code->operand1] = FSR[code->operand1]^0b00001000;
						return (code->absoluteAddress)+1;
						}	
						else if(code->operand2==4){
						FSR[code->operand1] = FSR[code->operand1]^0b00010000;
						return (code->absoluteAddress)+1;
						}	
						else if(code->operand2==5){
						FSR[code->operand1] = FSR[code->operand1]^0b00100000;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==6){
						FSR[code->operand1] = FSR[code->operand1]^0b01000000;
						return (code->absoluteAddress)+1;
						}
						else if(code->operand2==7){
						FSR[code->operand1] = FSR[code->operand1]^0b10000000;
						return (code->absoluteAddress)+1;
						}
						else{
						FSR[code->operand1] = FSR[code->operand1]^0b00000000;
						return (code->absoluteAddress)+1;
						}
					}
				}
				else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand3 == -4){
					if(FSR[BSR]>0x15){
						Throw(bsrRange);
					}
					else{
					if(code->operand2==0){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000001;
					return (code->absoluteAddress)+1;
					}
					else if(code->operand2==1){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000010;
					return (code->absoluteAddress)+1;
					}
					else if(code->operand2==2){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000100;
					return (code->absoluteAddress)+1;
					}	
					else if(code->operand2==3){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00001000;
					return (code->absoluteAddress)+1;
					}	
					else if(code->operand2==4){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00010000;
					return (code->absoluteAddress)+1;
					}	
					else if(code->operand2==5){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00100000;
					return (code->absoluteAddress)+1;
					}
					else if(code->operand2==6){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b01000000;
					return (code->absoluteAddress)+1;
					}
					else if(code->operand2==7){
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b10000000;
					return (code->absoluteAddress)+1;
					}
					else{
					FSR[(FSR[BSR]<<8)+code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000000;
					return (code->absoluteAddress)+1;
					}
					}
				}
		}
}

