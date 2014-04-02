#include "unity.h"
#include "TBLRDpostincf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_tblrdpostincf_should_pop_the_next_value() {



  Instruction inst = {

                      .mnemonic = TBLRD_post_increment,

                      .name = "tblrdpostincf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = -1,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };



  Table[0x00A356] = 0x55;







 tblrdpostincf(&code);

 UnityAssertEqualNumber((_U_SINT)((FSR[0xFF5])), (_U_SINT)((Table[0x00A356])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);



}
