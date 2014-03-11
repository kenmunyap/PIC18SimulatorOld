#include "unity.h"
#include "dCFSNZ.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_iORWF_if_operand2_and_operand3_equal_to_0() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x02,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0x33;



 dcfsnz(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX8);



}
