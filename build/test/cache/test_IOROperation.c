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

  UnityAssertEqualNumber((_U_SINT)((overRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

  printf("The file is overanged!\n");

 }

}

void test_iorwf_operand2_is_0_bsr_out_of_range_should_throw_error() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x1f;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

  printf("Overed BSR range!\n");

 }

}

void test_iorwf_operand2_is_3_should_throw_error() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 3,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 is over value!\n");

 }

}



void test_iorwf_operand2_is_negative_six_should_throw_error() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -6,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 is over value!\n");

 }

}

void test_iorwf_operand3_should_throw_error_with_value_negative_two() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -2,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put -2!\n");

 }

}

void test_iorwf_operand3_should_throw_error_with_value_negative_three() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -3,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put -3!\n");

 }

}

void test_iorwf_operand3_should_throw_error_with_W() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = W,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put W!\n");

 }

}

void test_iorwf_operand3_should_throw_error_with_F() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -2,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put F!\n");

 }

}

void test_iorwf_operand2_is_1_bsr_out_of_range_should_throw_error() {



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



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  iorwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

  printf("Overed BSR range!\n");

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



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[code.operand1])), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_HEX16);



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



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_HEX16);

}

void test_iorwf_operand2_negative_one_and_operand3_0() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -1,

                    .operand3 = 0,

                  };



 FSR[code.operand1] = 0x33;

 FSR[0xf8b] = 0x11;



 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[code.operand1])), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_HEX16);



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



 UnityAssertEqualNumber((_U_SINT)(_US16)((0x22)), (_U_SINT)(_US16)((FSR[0xf8b])), (((void *)0)), (_U_UINT)283, UNITY_DISPLAY_STYLE_HEX16);



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x22)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_HEX8);

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

 FSR[0xf8b] = 0x33;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x22;



 iorwf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)324, UNITY_DISPLAY_STYLE_HEX8);



}

void test_iorwf_operand2_1_in_file_register_and_operand3_banked_keyword() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = BANKED,

                  };



 FSR[0xf8b] = 0x11;

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_HEX8);

}

void test_iorwf_operand2_W_in_file_register_and_operand3_access() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = W,

                    .operand3 = ACCESS,

                  };



 FSR[0xf8b] = 0x11;

 FSR[code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_HEX8);

}

void test_iorwf_operand2_F_in_file_register_and_operand3_access() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = F,

                    .operand3 = ACCESS,

                  };



 FSR[0xf8b] = 0x11;

 FSR[code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)380, UNITY_DISPLAY_STYLE_HEX8);

}

void test_iorwf_operand2_1_in_file_register_and_operand3_access() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = ACCESS,

                  };



 FSR[0xf8b] = 0x11;

 FSR[code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_HEX8);

}

void test_iorwf_operand2_F_in_file_register_and_operand3_banked_keyword() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = F,

                    .operand3 = BANKED,

                  };



 FSR[0xf8b] = 0x11;

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)417, UNITY_DISPLAY_STYLE_HEX8);

}

void test_iorwf_operand2_W_in_file_register_and_operand3_banked_keyword() {



  Instruction inst = {

                      .mnemonic = IORWF,

                      .name = "iorwf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = W,

                    .operand3 = BANKED,

                  };



 FSR[0xf8b] = 0x11;

 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x11;

 iorwf(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)436, UNITY_DISPLAY_STYLE_HEX8);

}
