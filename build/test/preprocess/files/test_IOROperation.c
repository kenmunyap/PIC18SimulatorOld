#include "unity.h"
#include "iOR.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_iORWF_if_operand2_and_operand3_equal_to_0() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX16);



}



void test_iORWF_if_operand2_equal_to_1_and_operand3_equal_to_0() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[code.operand1])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX16);

}



void test_iORWF_if_operand2_equal_0_and_operand3_equal_to_1() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 1,

                  };





 FSR[0xf8b] = 0x11;

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x11;

 iorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX8);



}



void test_iORWF_if_operand2_operand3_equal_to_1() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 1,

                  };



 FSR[0xf8b] = 0x11;

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_HEX8);

}
