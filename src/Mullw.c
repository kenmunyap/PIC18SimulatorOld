#include <stdio.h>
#include "Bytecode.h"
#include "Mullw.h"


char FSR[0x1000];

void  mullw(Bytecode *code) {
	FSR[WREG] = FSR[WREG]*FSR[code->operand1];
	printf("%d",FSR[WREG]);
}