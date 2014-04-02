#include "unity.h"
#include "Bytecode.h"
#include "dAW.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_daw_all_operand_is_negative_one(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DAW,
                      .name = "daw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	-1,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
	
	
	FSR[WREG] = 0xA5;
	FSR[STATUS] = 0x02;
	daw(&code);
	TEST_ASSERT_EQUAL_HEX8(0x05,FSR[WREG]);
}

void test_daw_all_operand_is_not_negative_one(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DAW,
                      .name = "daw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x10,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,					
                  };
				  
	errorException error;
	
	Try{
		daw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(op_error,error);
	}
	
}