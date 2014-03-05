#include "unity.h"
#include "Bytecode.h"
#include "BitToggle.h"


void setUp() {}

void tearDown() {}



void test_bitToggle_if_operand3_equal_0_toggle_first() {



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x00;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX8);



}



void test_bitToggle_if_operand3_equal_0_toggle_last() {



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x80;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_HEX8);



}



void test_bitToggle_if_operand3_equal_1_toggle_first() {



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 2,

                    .operand3 = 1,

                  };

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_HEX8);



}



void test_bitToggle_if_operand3_equal_1_toggle_last(){

  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = 1,

      };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_HEX8);



}
