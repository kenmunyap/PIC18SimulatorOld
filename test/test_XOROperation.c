#include "unity.h"
#include "Bytecode.h"
#include "xOR.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_xorwf_file_over_0_or_255() {
  // Create test fixture
 
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xfff,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		printf("The file is overanged!\n");
		TEST_ASSERT_EQUAL(overRange,error);
	}
}

void test_xorwf_operand2_0_in_wreg_and_operand3_0_access_bank() {
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

void test_xorwf_operand2_1_in_wreg_and_operand3_0_access_bank() {
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

void test_xorwf_operand2_0_in_wreg_and_operand3_1_access_bank() {
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

void test_xorwf_operand2_1_in_wreg_and_operand3_1_access_bank() {
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

void test_xorwf_bsr_over_15(){
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
	

	FSR[BSR] = 0x1f;
	errorException bsrError;
	Try{
		xorwf(&code);
	}Catch(bsrError){
		printf("Over BSR range!!\n");
		TEST_ASSERT_EQUAL(bsrRange,bsrError);
	}
	
}
