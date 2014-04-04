#include <stdio.h>
#include "Bytecode.h"
#include "TBLRDpostincf.h"
#include "CException.h"

unsigned char FSR[0x1000];
int Table[0x200000];


int tblrdpostincf(Bytecode *code) {
		int temp,value;
		int temp0 = 0b111110000000000000000;
		int temp1 = 0b000001111111100000000;
		int temp2 = 0b000000000000011111111;
		
			FSR[TABLAT] = Table[(((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL]))];
			temp = ((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL]);
	
			temp++;
			
			FSR[TBLPTRU] = ((temp&temp0)>>16);
			FSR[TBLPTRH] = ((temp&temp1)>>8);
			FSR[TBLPTRL] = (temp&temp2);
			((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL]);
			Table[((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL])];
			
}