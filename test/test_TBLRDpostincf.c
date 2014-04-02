#include "unity.h"
#include "Bytecode.h"
#include "TBLRDpostincf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_tblrdpostincf_should_read_current_value_and_pointer_increment_to_next_value_and_should_take_second_memory_value() {

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
				  
			FSR[TBLPTRU] = 0x00;
			FSR[TBLPTRH] = 0xA3;
			FSR[TBLPTRL] = 0x56;
			Table[0x00A356] = 0x55;
			Table[0x00A357] = 0x34;
		
		
	
	tblrdpostincf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x55,FSR[TABLAT]);
	TEST_ASSERT_EQUAL_HEX32(0x00A357,((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL]));
	TEST_ASSERT_EQUAL_HEX8(0x34,Table[(((FSR[TBLPTRU])<<16) + ((FSR[TBLPTRH])<<8) + (FSR[TBLPTRL]))]);
	
}