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
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xDD,FSR[code.operand1]);
	
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
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xDD,FSR[WREG]);
}
void test_xorwf_operand2_negative_one_and_operand3_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = XORWF,
                      .name = "xorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 =  0,					
                  };
	
	FSR[code.operand1] = 0xFF;
	FSR[WREG] = 0xA8;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xA8,FSR[code.operand1]);
	
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
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xA8;
	FSR[WREG] = 0x11;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x46,FSR[code.operand1]);
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
	FSR[(FSR[BSR]<<8)+code.operand1] = 0xA8;
	FSR[WREG] = 0x11;
	
	xorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x46,FSR[WREG]);
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
	
	FSR[code.operand1] = 0xA8;
	FSR[WREG] = 0x11;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0x46,FSR[code.operand1]);
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
	
	FSR[code.operand1] = 0xFF;
	FSR[WREG] = 0xA8;
	
	xorwf(&code);

	TEST_ASSERT_EQUAL_HEX8(0xA8,FSR[WREG]);
}