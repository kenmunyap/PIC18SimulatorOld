#include <stdio.h>
#include "Bytecode.h"
#include "BitToggle.h"
#include "CException.h"

char unsigned FSR[0x1000];

void  bitToggle(Bytecode *code) {
	
	if(code->operand3 == -1){	
			code->operand3 = ACCESS;
	}
	if(code->operand3 == -2 || code->operand3 == W || code->operand3 == -3 || code->operand3 == F){
			Throw(error_operand3);
	}
	else if(code->operand1 <= 0x00 || code->operand1 >= 0xff){
				Throw(overRange);
	}
	else{
			if(code->operand3 == 0 || code->operand3 == ACCESS || code->operand3 == -5){
					if(code->operand1>=0x80){
						if(code->operand2 == 0){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000001;}
						else if(code->operand2==1){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000010;}
						else if(code->operand2==2){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000100;}	
						else if(code->operand2==3){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00001000;}	
						else if(code->operand2==4){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00010000;}	
						else if(code->operand2==5){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00100000;}
						else if(code->operand2==6){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b01000000;}
						else if(code->operand2==7){
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b10000000;}
						else{
						FSR[code->operand1] = FSR[(0xf<<8)+code->operand1]^0b00000000;}
					}
					else{
						if(code->operand2==0){
						FSR[code->operand1] = FSR[code->operand1]^0b00000001;}
						else if(code->operand2==1){
						FSR[code->operand1] = FSR[code->operand1]^0b00000010;}
						else if(code->operand2==2){
						FSR[code->operand1] = FSR[code->operand1]^0b00000100;}	
						else if(code->operand2==3){
						FSR[code->operand1] = FSR[code->operand1]^0b00001000;}	
						else if(code->operand2==4){
						FSR[code->operand1] = FSR[code->operand1]^0b00010000;}	
						else if(code->operand2==5){
						FSR[code->operand1] = FSR[code->operand1]^0b00100000;}
						else if(code->operand2==6){
						FSR[code->operand1] = FSR[code->operand1]^0b01000000;}
						else if(code->operand2==7){
						FSR[code->operand1] = FSR[code->operand1]^0b10000000;}
						else{
						FSR[code->operand1] = FSR[code->operand1]^0b00000000;}
					}
				}
				else if(code->operand3 == 1 || code->operand3 == BANKED || code->operand3 == -4){
					if(FSR[BSR]>0x15){
						Throw(bsrRange);
					}
					else{
					if(code->operand2==0){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000001;}
					else if(code->operand2==1){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000010;}
					else if(code->operand2==2){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000100;}	
					else if(code->operand2==3){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00001000;}	
					else if(code->operand2==4){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00010000;}	
					else if(code->operand2==5){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00100000;}
					else if(code->operand2==6){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b01000000;}
					else if(code->operand2==7){
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b10000000;}
					else{
					FSR[code->operand1] = FSR[(FSR[BSR]<<8)+code->operand1]^0b00000000;}
					}
				}
		}
}

