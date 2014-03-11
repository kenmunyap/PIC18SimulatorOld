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
		printf("Your file register is over ranged!\n");
		TEST_ASSERT_EQUAL(overRange,error);
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

