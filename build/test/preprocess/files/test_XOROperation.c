#include "xOR.h"
#include "unity.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}







void test_xorwf_file_over_0_or_255() {





  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

                    .operand2 = 0,

                    .operand3 = 0,

                  };

 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("The file is overanged!\n");

  UnityAssertEqualNumber((_U_SINT)((overRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

 }

}

void test_xorwf_operand2_is_0_bsr_out_of_range_should_throw_error(){





  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 1,

                  };





 FSR[0xfE0] = 0x1f;

 errorException bsrError;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { bsrError = CExceptionFrames[MY_ID].Exception; bsrError=bsrError; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((bsrError)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

  printf("Over BSR range!!\n");

 }

}

void test_xorwf_operand2_is_3_should_throw_error() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 3,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 is over value!\n");

 }

}

void test_xorwf_operand3_should_throw_error_with_value_negative_two() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -2,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put -2!\n");

 }

}

void test_xorwf_operand3_should_throw_error_with_value_negative_three() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -3,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put -3!\n");

 }

}

void test_xorwf_operand2_is_negative_six_should_throw_error() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -6,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 is over value!\n");

 }

}

void test_xorwf_operand3_should_throw_error_with_W() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = W,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put W!\n");

 }

}

void test_xorwf_operand3_should_throw_error_with_F() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = F,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  xorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put F!\n");

 }

}









void test_xorwf_operand2_negative_one_and_operand3_negative_one() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -1,

                    .operand3 = -1,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xDD)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_HEX8);



}

void test_xorwf_operand2_0_wreg_and_operand3_negative_one() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -1,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xDD)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_negative_one_and_operand3_0() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -1,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0xFF;

 FSR[0xf8b] = 0xA8;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA8)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_HEX8);



}

void test_xorwf_operand2_0_in_wreg_and_operand3_0_access_bank() {



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA8)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_1_in_wreg_and_operand3_0_access_bank() {



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)285, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_0_in_wreg_and_operand3_1_access_bank() {



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

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_1_in_wreg_and_operand3_1_access_bank() {



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

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)322, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_1_in_wreg_and_operand3_banked_keyword() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = BANKED,

                  };



 FSR[0xfE0]= 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_W_keyword_and_operand3_banked_keyword() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = W,

                    .operand3 = BANKED,

                  };

 FSR[0xfE0]= 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)359, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_F_keyword_and_operand3_access_keyword() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = F,

                    .operand3 = ACCESS,

                  };



 FSR[code.operand1] = 0xA8;

 FSR[0xf8b] = 0x11;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x46)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)378, UNITY_DISPLAY_STYLE_HEX8);

}

void test_xorwf_operand2_W_keyword_and_operand3_access_keyword() {



  Instruction inst = {

                      .mnemonic = XORWF,

                      .name = "xorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = W,

                    .operand3 = ACCESS,

                  };



 FSR[code.operand1] = 0xFF;

 FSR[0xf8b] = 0xA8;



 xorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA8)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_HEX8);

}
