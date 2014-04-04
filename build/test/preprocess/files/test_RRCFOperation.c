#include "unity.h"
#include "rRCF.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_rrcf_operand2_F_in_file_register_and_operand3_access() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 0,

                    .operand3 = 0,

                  };





 FSR[code.operand1] = 0b11100110;

 FSR[0xfd8] = 0;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b01110011)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_Banked_operand3_is_off() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = BANKED,

                    .operand3 = -1,

                  };



 FSR[0xfE0] = 0x1;

 FSR[0x143] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[0x143])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_ACCESS_operand3_is_off() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = ACCESS,

                    .operand3 = -1,

                  };





 FSR[code.operand1] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_ACCESS_and_larger_than_80_operand3_is_off() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x81,

                    .operand2 = ACCESS,

                    .operand3 = -1,

                  };





 FSR[0xf81] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[0xf81])), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_is_negative_1_and_Larger_than_80_operand3_is_negative_1() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x81,

                    .operand2 = -1,

                    .operand3 = -1,

                  };





 FSR[0xf81] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[0xf81])), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_is_negative_1_operand3_is_negative_1() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = -1,

                    .operand3 = -1,

                  };





 FSR[code.operand1] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_BANKED_operand3_is_negative_1() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = BANKED,

                    .operand3 = -1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[0x143] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[0x143])), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);

}



void test_rrcf_operand2_ACCESS_operand3_is_negative_1() {



  Instruction inst = {

                      .mnemonic = RRCF,

                      .name = "rrcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = ACCESS,

                    .operand3 = -1,

                  };





 FSR[code.operand1] = 0b11100110;

 FSR[0xfd8] = 1;

 rrcf(&code);

 UnityAssertEqualNumber((_U_SINT)((0b11110011)), (_U_SINT)((FSR[0x43])), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b10000001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

}
