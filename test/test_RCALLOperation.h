#include "unity.h"
#include "Bytecode.h"
#include "rCALL.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_rcall_should_pop_the_next_value() {

  Instruction inst = {
                      .mnemonic = RCALL,
                      .name = "rcall"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x1000,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,	
					.absoluteAddress = 0x100					
                  };
				  
	PC = code.absoluteAddress;
	PC = 0x01AAAB;
	rcall(&code);
	TEST_ASSERT_EQUAL_HEX8(0x01,FSR[TOSU]);
	TEST_ASSERT_EQUAL_HEX8(0xAA,FSR[TOSH]);
	TEST_ASSERT_EQUAL_HEX8(0xAB,FSR[TOSL]);
	TEST_ASSERT_EQUAL_HEX16(0x102,PC);
	
}
