#include "unity.h"
#include "Mullw.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_Mullw_store_into_PRODH_and_PRODL(){





  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xC4,

                    .operand2 = -1,

                    .operand3 =-1,

                  };





 FSR[0xFE8] = 0xE2;

 mullw(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xAD)), (_U_SINT)(_US8 )((FSR[0xFF4])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x08)), (_U_SINT)(_US8 )((FSR[0xFF3])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX8);

}
