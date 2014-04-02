#include "unity.h"
#include "Bytecode.h"
#include "TBLRDpostincf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_tblrdpostincf_should_pop_the_next_value() {

  Instruction inst = {
                      .mnemonic = TBLRD_post_increment,
                      .name = "tblrdpostincf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	-1,  //address of file select register
                    .operand2 =	-1, 	  
                    .operand3 = -1,	
					.absoluteAddress = 0x100					
                  };
				 uhl;
		Table[0x00A356] = 0x55;
		
		
	
	tblrdpostincf(&code);
	TEST_ASSERT_EQUAL(FSR[TABLAT],Table[0x00A356]);
	
}