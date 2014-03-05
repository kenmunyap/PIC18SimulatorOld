#include "unity.h"
#include "Bytecode.h"
#include "BitToggle.h"

void setUp() {}
void tearDown() {}

void test_bitToggle_the_last_bit_need_to_toggle() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	0, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0b00000000;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL(0b00000001,FSR[code.operand1]);
  
}

void test_bitToggle_the_second_last_bit_need_to_toggle() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0b00000010;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL(0b00000000,FSR[code.operand1]);
  
}

void test_bitToggle_the_first_bit_need_to_toggle() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register;
                    .operand2 =	2, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0b00000010; // value of operand1 
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL(0b00000110,FSR[code.operand1]);
  
}

void test_bitToggle_the_rotate_operand1_to_bank_address(){
	 Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
	 Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register;
                    .operand2 =	2, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
					 };
				  
	FSR[code.operand1]=0b00000010; // value of operand1 
	bitToggle(&code);

	TEST_ASSERT_EQUAL(0b00000110,FSR[code.operand1]);						
	TEST_ASSERT_EQUAL_HEX8(0x06,FSR[BSR]);	

}