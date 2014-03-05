#include <stdio.h>
#include "Bytecode.h"
#include "BitToggle.h"


char FSR[0x1000];

void  bitToggle(Bytecode *code) {
	/*	
	*	TEST which bits need to be toggle;
	*	operand2 control the bit which need to toggle;
	*	operand1 :is to set the value;
	*			  after set value then check which bit need to toggle;
	*			  save back the toggle value;
	*/
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
	
	/*	
	*	TEST which address need to store value;
	*	operand3 :1 0 is off bank;
	*			  2 1 is on  bank;
	*	operand1 :push the value combine to bank;
	*/
	
	if(code->operand3==1){
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
		else {
			FSR[code->operand1];
		}
	}
	
}

