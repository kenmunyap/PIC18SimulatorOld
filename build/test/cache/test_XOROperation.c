#include "xOR.h"
#include "unity.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_iORWF_if_operand2_and_operand3_equal_0() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0xFF;

 FSR[0xf8b] = 0xA8;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA8)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iORWF_if_operand2_equal_1_and_operand3_equal_0() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iORWF_if_operand2_equal_0_and_operand3_equal_1() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 1,

                  };

 FSR[0xfE0]= 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iORWF_if_operand2_equal_1_and_operand3_equal_1() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 1,

                  };



 FSR[0xfE0]= 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_HEX8);

}
