#include "unity.h"
#include "Bytecode.h"
#include "dCFSNZ.h"
#include "CException.h"

void setUp() {}
void tearDown() {}
/*
 error checking
 */
void test_dcfsnz_file_over_0_or_255() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xfff,  //address of file select register
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(overRange,error);
		printf("The file is overanged!\n");	
	}
}
void test_dcfsnz_operand2_is_0_bsr_out_of_range_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0x1f;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(bsrRange,error);
		printf("Overed BSR range!\n");
	}
}
void test_dcfsnz_operand2_is_3_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 3, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 is over value!\n");
	}
}
void test_dcfsnz_operand2_is_negative_six_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 -6, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 is over value!\n");
	}
}
void test_dcfsnz_operand3_should_throw_error_with_value_negative_two() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  -2,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put -2!\n");
	}
}
void test_dcfsnz_operand3_should_throw_error_with_value_negative_three() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  -3,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put -3!\n");
	}
}
void test_dcfsnz_operand3_should_throw_error_with_W() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  W,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put W!\n");
	}
}
void test_dcfsnz_operand3_should_throw_error_with_F() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 0, 	  
                    .operand3 =  F,					
                  };
	
	FSR[BSR] = 0xf;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 cannot put F!\n");
	}
}
void test_dcfsnz_operand2_is_1_bsr_out_of_range_should_throw_error() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x34,  //address of file select register
                    .operand2 =	 1, 	  
                    .operand3 =  1,					
                  };
	
	FSR[BSR] = 0x1f;
	
	errorException error;
	Try{
		dcfsnz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(bsrRange,error);
		printf("Overed BSR range!\n");
	}
}

/*
test normal
*/

void test_dcfsnz_operand2_negative_one_and_operand3_negative_one_absoluteAddress_equal_zero() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,	
					.absoluteAddress = 0x100					
                  };
	
	FSR[code.operand1] = 0x01;

	
	dcfsnz(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);

}
void test_dcfsnz_operand2_negative_one_and_operand3_negative_one_absoluteAddress_not_equal_zero() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,	
					.absoluteAddress = 0x100					
                  };
	
	FSR[code.operand1] = 0x11;

	
	dcfsnz(&code);

	TEST_ASSERT_EQUAL_HEX8(0x10,FSR[code.operand1]);

}




