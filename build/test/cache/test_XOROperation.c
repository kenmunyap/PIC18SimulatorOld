#include "xOR.h"
#include "unity.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_iORWF_save_in_WREG() {



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



void test_iORWF_save_in_file_register() {



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iORWF_save_in_BSR() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 10,

                  };



 FSR[code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x0A)), (_U_SINT)(_US8 )((code.operand3)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[0xfE0])), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iORWF_save_in_access_bank() {



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



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((code.operand3)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_HEX8);

}
