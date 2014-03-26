#include "unity.h"
#include "Bytecode.h"
#include "Mullw.h"
#include <inttypes.h>
#include "CException.h"
void setUp() {}
void tearDown() {}

void test_mullw_operand1_is_over_0_or_255(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MULLW,
                      .name = "mullw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xfff,  
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	errorException error;
	Try{
		mullw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(overRange,error);
		printf("Your file register is over ranged!\n");
	}
}

void test_mullw_store_into_PRODH_and_PRODL(){

  // Create test fixture
  Instruction inst = {
                      .mnemonic = MULLW,
                      .name = "mullw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xC4,
                    .operand2 =	-1,
                    .operand3 =-1,			
                  };

	
	FSR[WREG] = 0xE2;
	mullw(&code);
	TEST_ASSERT_EQUAL_HEX8(0xAD,FSR[PRODH]);
	TEST_ASSERT_EQUAL_HEX8(0x08,FSR[PRODL]);	
}

void test_mullw_operand3_is_not_close_throw_error(){

  // Create test fixture
  Instruction inst = {
                      .mnemonic = MULLW,
                      .name = "mullw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xC4,
                    .operand2 =	-1,
                    .operand3 = 0,			
                  };

	
	errorException error;
	Try{
		mullw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_3error,error);
		printf("operand3 got value!\n");
	}
}

void test_mullw_operand2_is_not_close_throw_error(){

  // Create test fixture
  Instruction inst = {
                      .mnemonic = MULLW,
                      .name = "mullw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xC4,
                    .operand2 =	 0,
                    .operand3 = -1,			
                  };

	
	errorException error;
	Try{
		mullw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_2error,error);
		printf("operand2 got value!\n");
	}
}

void test_mullw_operand2_and_operand3_is_not_close_throw_error(){

  // Create test fixture
  Instruction inst = {
                      .mnemonic = MULLW,
                      .name = "mullw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xC4,
                    .operand2 =	 0,
                    .operand3 =  0,			
                  };

	
	errorException error;
	Try{
		mullw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_error,error);
		printf("operand2 and 3 got value!\n");
	}
}