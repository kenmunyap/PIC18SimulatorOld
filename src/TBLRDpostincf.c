#include <stdio.h>
#include "Bytecode.h"
#include "TBLRDpostincf.h"
#include "CException.h"

unsigned char FSR[0x1000];
int Table[0x200000];


void tblrdpostincf(Bytecode *code) {
		int temp,value;

			FSR[TABLAT] = Table[((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL])];

	
	  
}