#include "unity.h"
#include "Bytecode.h"
#include "Mullw.h"

void setUp() {}
void tearDown() {}

void test_bitToggle_the_last_bit_need_to_toggle() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MULLW,
                      .name = "mullw"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xC4,
                    .operand2 =	-1,
                    .operand3 = -1,			
                  };
				  
	FSR[WREG] = 0xE2;
	
	mullw(&code);

  
}