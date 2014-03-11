#include "unity.h"
#include "Bytecode.h"
#include "iOR.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_iorwf_file_over_0_or_255() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xfff,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		printf("The file is overanged!\n");
		TEST_ASSERT_EQUAL(overRange,error);
	}
}

void test_iorwf_operand2_negative_one_and_operand3_negative_one() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX16(0x11,FSR[WREG]);
	
}

void test_iorwf_operand2_0_wreg_and_operand3_negative_one() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = -1,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX16(0x22,FSR[WREG]);
	
}
void test_iorwf_operand2_0_in_wreg_and_operand3_0_access_bank() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX16(0x22,FSR[WREG]);
	
}

void test_iorwf_operand2_1_in_file_register_and_operand3_0_access_bank() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX16(0x22,FSR[code.operand1]);
}


void test_iorwf_operand2_0_in_wreg_and_operand3_1_bank_select_register() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = 1,					
                  };
	
	
	FSR[WREG] = 0x11;
	FSR[BSR] = 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x11;
	
	iorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[WREG]);
	
}

void test_iorwf_operand2_1_in_file_register_and_operand3_1_bank_select_register() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[BSR] = 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
}

void test_iorwf_bsr_over_15() {
  // Create test fixture
 
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
	

	FSR[BSR] = 0x1f;
	errorException bsrError;
	Try{
		iorwf(&code);
	}Catch(bsrError){
		printf("Over BSR range!!\n");
		TEST_ASSERT_EQUAL(bsrRange,bsrError);
	}
	
}
