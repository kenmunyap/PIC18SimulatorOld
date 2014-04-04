#include "unity.h"
#include "rCALL.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_rcall_should_pop_the_next_value() {



  Instruction inst = {

                      .mnemonic = RCALL,

                      .name = "rcall"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x1000,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };



 PC = code.absoluteAddress;

 PC = 0x01AAAB;

 rcall(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[0xFFF])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xAA)), (_U_SINT)(_US8 )((FSR[0xFFE])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xAB)), (_U_SINT)(_US8 )((FSR[0xFFD])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x102)), (_U_SINT)(_US16)((PC)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_HEX16);



}
