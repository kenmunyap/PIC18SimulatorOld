#include "unity.h"
#include "Bytecode.h"
#include "POP.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_pop_should_pop_the_next_value() {

  Instruction inst = {
                      .mnemonic = POP,
                      .name = "pop"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	-1,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,	
					.absoluteAddress = 0x100					
                  };
	FSR[STKPTR] = 10;			  
	PIC18Stack[10] = 0x0031A2;
	PIC18Stack[9] = 0x014332;

	pop(&code);
	
	TEST_ASSERT_EQUAL(9,FSR[STKPTR]);
	TEST_ASSERT_EQUAL_HEX32(0x0031A2,PC);
	TEST_ASSERT_EQUAL_HEX8(0x01,FSR[TOSU]);
	TEST_ASSERT_EQUAL_HEX8(0x43,FSR[TOSH]);
	TEST_ASSERT_EQUAL_HEX8(0x32,FSR[TOSL]);
}

void test_pop_operand1_is_not_off(){

	Instruction inst = {
                      .mnemonic = POP,
                      .name = "pop"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x11,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,	
					.absoluteAddress = 0x100					
                  };
				  
	errorException error;
	Try{
		pop(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_error,error);
	}
}


