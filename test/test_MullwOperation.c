#include "unity.h"
#include "Bytecode.h"
#include "Mullw.h"
#include <inttypes.h>
	
void setUp() {}
void tearDown() {}

void test_Mullw_store_into_PRODH_and_PRODL(){

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