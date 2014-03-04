#include "unity.h"
#include "Bytecode.h"
#include "BitToggle.h"


void setUp() {}

void tearDown() {}



void test_bitToggle_the_last_bit_need_to_toggle() {



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0b00000000;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)((0b00000001)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);



}



void test_bitToggle_the_second_last_bit_need_to_toggle() {



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 1,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0b00000010;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);



}



void test_bitToggle_the_first_bit_need_to_toggle() {



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 2,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0b00000010;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)((0b00000110)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);



}



void test_bitToggle_the_rotate_operand1_to_bank_address(){

  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 2,

                    .operand3 = 1,

      };



 FSR[code.operand1]=0b00000010;

 FSR[0xfE0]=3;

 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)((0b00000110)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x03)), (_U_SINT)(_US8 )((FSR[0xfE0])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_HEX8);



}
