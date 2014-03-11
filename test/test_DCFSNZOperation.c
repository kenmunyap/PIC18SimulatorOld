#include "unity.h"
#include "Bytecode.h"
#include "dCFSNZ.h"

void setUp() {}
void tearDown() {}

void test_iORWF_if_operand2_and_operand3_equal_to_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = DCFSNZ,
                      .name = "dcfsnz"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x02,  //address of file select register
                    .operand2 =	0, 	  // this is select which case need to be toggle;
                    .operand3 = 0,					
                  };
	
	FSR[code.operand1] = 0x33;
	
	dcfsnz(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[WREG]);
	
}