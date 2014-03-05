#include "unity.h"
#include "Bytecode.h"
#include "iOR.h"

void setUp() {}
void tearDown() {}

void test_iORWF_save_in_WREG() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	0, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x33;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL(0x00,FSR[WREG]);
	
}

void test_iORWF_save_in_file_register() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x33;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL(0x00,FSR[code.operand1]);
}

void test_iORWF_save_in_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 10,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x0A,code.operand3);
	TEST_ASSERT_EQUAL(0x22,FSR[BSR]);
}

void test_iORWF_save_in_access_bank() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,code.operand3);
	TEST_ASSERT_EQUAL(0x22,FSR[code.operand1]);
}
