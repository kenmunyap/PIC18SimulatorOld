#include "unity.h"
#include "Bytecode.h"
#include "iOR.h"
#include "CException.h"

void setUp() {}
void tearDown() {}
/*
	Test error
*/
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
		TEST_ASSERT_EQUAL(overRange,error);
		printf("The file is overanged!\n");	
	}
}
void test_iorwf_operand2_is_0_bsr_out_of_range_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0x1f;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(bsrRange,error);
		printf("Overed BSR range!\n");
	}
}
void test_iorwf_operand2_is_3_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 3, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 is over value!\n");
	}
}
void test_iorwf_operand2_is_negative_six_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 -6, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 is over value!\n");
	}
}
void test_iorwf_operand3_should_throw_error_with_value_negative_two() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  -2,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put -2!\n");
	}
}
void test_iorwf_operand3_should_throw_error_with_value_negative_three() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  -3,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put -3!\n");
	}
}
void test_iorwf_operand3_should_throw_error_with_W() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  W,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put W!\n");
	}
}
void test_iorwf_operand3_should_throw_error_with_F() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  F,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put F!\n");
	}
}
void test_iorwf_operand2_is_1_bsr_out_of_range_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 1, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0x1f;
	
	errorException error;
	Try{
		iorwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(bsrRange,error);
		printf("Overed BSR range!\n");
	}
}

/*
	Test work normal
*/

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

	TEST_ASSERT_EQUAL_HEX16(0x22,FSR[code.operand1]);
	
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
void test_iorwf_operand2_negative_one_and_operand3_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 =  0,					
                  };
	
	FSR[code.operand1] = 0x33;
	FSR[WREG] = 0x11;
	
	iorwf(&code);

	TEST_ASSERT_EQUAL_HEX16(0x22,FSR[code.operand1]);
	
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

	TEST_ASSERT_EQUAL_HEX8(0x22,FSR[code.operand1]);
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
	
	
	
	FSR[BSR] = 0x01;
	FSR[WREG] = 0x33;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x22;
	
	iorwf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x11,FSR[WREG]);
	
}
void test_iorwf_operand2_1_in_file_register_and_operand3_banked_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = BANKED,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[BSR] = 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
}
void test_iorwf_operand2_W_in_file_register_and_operand3_access() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	W, 	  // this is select which case need to be toggle;
                    .operand3 = ACCESS,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[WREG]);
}
void test_iorwf_operand2_F_in_file_register_and_operand3_access() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	F, 	  // this is select which case need to be toggle;
                    .operand3 = ACCESS,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
}
void test_iorwf_operand2_1_in_file_register_and_operand3_access() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = ACCESS,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
}
void test_iorwf_operand2_F_in_file_register_and_operand3_banked_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	F, 	  // this is select which case need to be toggle;
                    .operand3 = BANKED,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[BSR] = 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);
}
void test_iorwf_operand2_W_in_file_register_and_operand3_banked_keyword() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = IORWF,
                      .name = "iorwf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	W, 	  // this is select which case need to be toggle;
                    .operand3 = BANKED,					
                  };
	
	FSR[WREG] = 0x11;
	FSR[BSR] = 0x01;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x11;
	iorwf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[WREG]);
}
