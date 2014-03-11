#include "unity.h"
#include "iOR.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_iorwf_file_over_0_or_255() {



  int error;

  int overRange;

  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("The file is overanged!\n");

  if (((overRange) != (error))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)27);;};

 }

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



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_HEX16);



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



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[code.operand1])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_HEX16);

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





 FSR[0xf8b] = 0x11;

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x11;



 iorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_HEX8);



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_HEX8);

}



void test_iorwf_bsr_over_15() {



  int bsrRange;

  int bsrOverRange;

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



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { bsrOverRange = CExceptionFrames[MY_ID].Exception; bsrOverRange=bsrOverRange; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("Over BSR range!!\n");

  if (((bsrRange) != (bsrOverRange))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)135);;};

 }



}
