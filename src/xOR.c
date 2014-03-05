#include <stdio.h>
#include "Bytecode.h"
#include "xOR.h"


char FSR[0x1000];

void  xorwf(Bytecode *code) {
	/*	
	*	operand2 : 1 select save in file register 
	*   		   0 select save in WREG
	*/
		int temp,temp1;
		if(code->operand2 == 0){
			temp=FSR[code->operand1]^FSR[WREG];
			FSR[WREG] = ~(temp);
		}
		else{
			temp1=FSR[code->operand1]^FSR[WREG];
			FSR[code->operand1] = ~(temp1);
		}
		
		
	/*	
	*	operand3 : 1 save in BSR
	*   		   0 Save in Access Bank
	*/
	
		if(code->operand3 == 0){
			FSR[code->operand1];
		}
		else{
			FSR[BSR]=(FSR[BSR]<<8)+FSR[code->operand1]; 	
			if(FSR[BSR]==0){
				FSR[BSR] = 0x00;}
			else if(FSR[BSR]==1){
				FSR[BSR] = 0x01;}
			else if(FSR[BSR]==2){
				FSR[BSR] = 0x02;}
			else if(FSR[BSR]==3){
				FSR[BSR] = 0x03;}
			else if(FSR[BSR]==4){
				FSR[BSR] = 0x04;}
			else if(FSR[BSR]==5){
				FSR[BSR] = 0x05;}
			else if(FSR[BSR]==6){
				FSR[BSR] = 0x06;}
			else if(FSR[BSR]==7){
				FSR[BSR] = 0x07;}
			else if(FSR[BSR]==8){
				FSR[BSR] = 0x08;}
			else if(FSR[BSR]==9){
				FSR[BSR] = 0x09;}
			else if(FSR[BSR]==10){
				FSR[BSR] = 0x0A;}
			else if(FSR[BSR]==11){
				FSR[BSR] = 0x0B;}
			else if(FSR[BSR]==12){
				FSR[BSR] = 0x0C;}
			else if(FSR[BSR]==13){
				FSR[BSR] = 0x0D;}
			else if(FSR[BSR]==14){
				FSR[BSR] = 0x0E;}
			else if(FSR[BSR]==15){
				FSR[BSR] = 0x0F;}
			else{
			}
	
	}
			
}	
		
		
		
		
	
