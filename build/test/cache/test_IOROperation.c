#include "unity.h"
#include "iOR.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_iorwf_file_over_0_or_255() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

                    .operand2 = 0,

                    .operand3 = 0,

                  };

 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("The file is overanged!\n");

  UnityAssertEqualNumber((_U_SINT)((overRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_iorwf_operand2_negative_one_and_operand3_negative_one() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -1,

                    .operand3 = -1,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x11)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX16);



}



void test_iorwf_operand2_0_wreg_and_operand3_negative_one() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -1,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_HEX16);



}

void test_iorwf_operand2_0_in_wreg_and_operand3_0_access_bank() {



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



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_HEX16);



}



void test_iorwf_operand2_1_in_file_register_and_operand3_0_access_bank() {



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x22)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_HEX8);

}





void test_iorwf_operand2_0_in_wreg_and_operand3_1_bank_select_register() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 1,

                  };







 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x22;

 FSR[0xf8b] = 0x33;

 iorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_HEX8);



}



void test_iorwf_operand2_1_in_file_register_and_operand3_1_bank_select_register() {



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iorwf_bsr_over_15() {





  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 1,

                  };





 FSR[0xfE0] = 0x1f;

 errorException bsrError;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { bsrError = CExceptionFrames[MY_ID].Exception; bsrError=bsrError; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("Over BSR range!!\n");

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((bsrError)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

 }



}
