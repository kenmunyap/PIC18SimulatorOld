#include "unity.h"
#include "Bytecode.h"
#include "BitToggle.h"

void setUp() {}
void tearDown() {}

void test_bitToggle_if_operand3_equal_0_toggle_first() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x00;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x01,FSR[code.operand1]);
  
}

void test_bitToggle_if_operand3_equal_0_toggle_last() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x80;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
  
}

void test_bitToggle_if_operand3_equal_1_toggle_first() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	2, 	  
                    .operand3 = 1,					
                  };
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x14,FSR[code.operand1]);
  
}

void test_bitToggle_if_operand3_equal_1_toggle_last(){
	 Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
	 Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register;
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
					 };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[code.operand1]);

}
