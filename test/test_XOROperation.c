#include "unity.h"
#include "Bytecode.h"
#include "xOR.h"

void setUp() {}
void tearDown() {}

void test_iORWF_if_operand2_and_operand3_equal_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  
                    .operand2 =	0, 	 
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0xFF;
	FSR[WREG] = 0xA8;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xA8,FSR[WREG]);
}

void test_iORWF_if_operand2_equal_1_and_operand3_equal_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34, 
                    .operand2 =	1, 	  
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0xA8;
	FSR[WREG] = 0x11;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x46,FSR[code.operand1]);
}

void test_iORWF_if_operand2_equal_0_and_operand3_equal_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	0, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
	FSR[BSR]= 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xA8;
	FSR[WREG] = 0x11;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x46,FSR[WREG]);
}

void test_iORWF_if_operand2_equal_1_and_operand3_equal_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
	
	FSR[BSR]= 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xA8;
	FSR[WREG] = 0x11;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x46,FSR[code.operand1]);
}
