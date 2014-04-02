#include "unity.h"
#include "Bytecode.h"
#include "xOR.h"
#include "CException.h"

void setUp() {}
void tearDown() {}
/*
	Test error
*/
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
void test_xorwf_operand2_is_0_bsr_out_of_range_should_throw_error(){
  // Create test fixture

  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  
                    .operand2 =	0, 	  
                    .operand3 = 1,					
                  };
	

	FSR[BSR] = 0x1f;
	errorException bsrError;
	Try{
		xorwf(&code);
	}Catch(bsrError){
		TEST_ASSERT_EQUAL(bsrRange,bsrError);
		printf("Over BSR range!!\n");	
	}
}
void test_xorwf_operand2_is_3_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 3, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 is over value!\n");
	}
}
void test_xorwf_operand3_should_throw_error_with_value_negative_two() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  -2,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put -2!\n");
	}
}
void test_xorwf_operand3_should_throw_error_with_value_negative_three() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  -3,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put -3!\n");
	}
}
void test_xorwf_operand2_is_negative_six_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 -6, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 is over value!\n");
	}
}
void test_xorwf_operand3_should_throw_error_with_W() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  W,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put W!\n");
	}
}
void test_xorwf_operand3_should_throw_error_with_F() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  F,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		xorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put F!\n");
	}
}

/*
	Test work normal
*/
void test_xorwf_operand2_negative_one_and_operand3_negative_one() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	FSR[code.operand1] = 0x00;
	FSR[WREG] = 0xAA;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xAA,FSR[code.operand1]);
	TEST_ASSERT_EQUAL_HEX8(0x80,FSR[STATUS]);
}
void test_xorwf_operand2_0_wreg_and_operand3_negative_one() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = -1,					
                  };
	
	FSR[code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[WREG]);
}
void test_xorwf_operand2_negative_one_and_operand3_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x81,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 =  0,					
                  };
	
	FSR[((0xf)<<8)+code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[0xf81]);
	
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
	
	FSR[code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[WREG]);
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
	
	FSR[code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[code.operand1]);
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
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[WREG]);
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
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX16(0x001A,FSR[0x134]);
}
void test_xorwf_operand2_1_in_wreg_and_operand3_banked_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = BANKED,					
                  };
	
	FSR[BSR]= 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[0x134]);
}
void test_xorwf_operand2_W_keyword_and_operand3_banked_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	W, 	  // this is select which case need to be toggle;
                    .operand3 = BANKED,					
                  };
	FSR[BSR]= 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[WREG]);
}
void test_xorwf_operand2_F_keyword_and_operand3_access_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34, 
                    .operand2 =	F, 	  
                    .operand3 = ACCESS,					
                  };
	
	FSR[code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[code.operand1]);
}
void test_xorwf_operand2_W_keyword_and_operand3_access_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  
                    .operand2 =	W, 	 
                    .operand3 = ACCESS,					
                  };
	
	FSR[code.operand1] = 0xAF;
	FSR[WREG] = 0xB5;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x1A,FSR[WREG]);
}

/*
*check status
*/

void test_xorwf_operand1_0_and_wreg_0_status_will_get_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	FSR[code.operand1] = 0x00;
	FSR[WREG] = 0x00;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
	TEST_ASSERT_EQUAL_HEX8(0x04,FSR[STATUS]);
}
void test_xorwf_operand1_is_negative_value_and_wreg_0_status_will_get_80() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	FSR[code.operand1] = 0xAA;
	FSR[WREG] = 0x00;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xAA,FSR[code.operand1]);
	TEST_ASSERT_EQUAL_HEX8(0x80,FSR[STATUS]);
}