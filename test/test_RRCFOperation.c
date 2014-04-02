#include "unity.h"
#include "Bytecode.h"
#include "rRCF.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_rrcf_operand2_F_in_file_register_and_operand3_access() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	
	
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 0;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b01110011,FSR[code.operand1]);
}

void test_rrcf_operand2_Banked_operand3_is_off() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	BANKED, 	
                    .operand3 = -1,					
                  };
	
	FSR[BSR] = 0x1;
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[0x143]);
}

void test_rrcf_operand2_ACCESS_operand3_is_off() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43, 
                    .operand2 =	ACCESS, 	
                    .operand3 = -1,					
                  };
	
	
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[code.operand1]);
}

void test_rrcf_operand2_ACCESS_and_larger_than_80_operand3_is_off() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x81,  
                    .operand2 =	ACCESS, 	 
                    .operand3 = -1,					
                  };
	
	
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[0xf81]);
}

void test_rrcf_operand2_is_negative_1_and_Larger_than_80_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x81, 
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[0xf81]);
}

void test_rrcf_operand2_is_negative_1_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43, 
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[code.operand1]);
}

void test_rrcf_operand2_BANKED_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43, 
                    .operand2 =	BANKED, 	  
                    .operand3 = -1,					
                  };
	
	FSR[BSR] = 0x01;
	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[0x143]);
}

void test_rrcf_operand2_ACCESS_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRCF,
                      .name = "rrcf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43, 
                    .operand2 =	ACCESS, 	  
                    .operand3 = -1,					
                  };
	

	FSR[code.operand1] = 0b11100110;
	FSR[STATUS] = 1;
	rrcf(&code);
	TEST_ASSERT_EQUAL(0b11110011,FSR[0x143]);
	TEST_ASSERT_EQUAL(0b10000001,FSR[STATUS]);
}




