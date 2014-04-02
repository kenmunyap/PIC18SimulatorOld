#include "unity.h"
#include "dCFSNZ.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}







void test_dcfsnz_file_over_0_or_255() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

                    .operand2 = 0,

                    .operand3 = 0,

                  };

 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((overRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

  printf("The file is overanged!\n");

 }

}

void test_dcfsnz_operand2_is_0_bsr_out_of_range_should_throw_error() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x1f;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

  printf("Overed BSR range!\n");

 }

}

void test_dcfsnz_operand2_is_3_should_throw_error() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 3,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 is over value!\n");

 }

}

void test_dcfsnz_operand2_is_negative_six_should_throw_error() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = -6,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 is over value!\n");

 }

}

void test_dcfsnz_operand3_should_throw_error_with_value_negative_two() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -2,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put -2!\n");

 }

}

void test_dcfsnz_operand3_should_throw_error_with_value_negative_three() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = -3,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put -3!\n");

 }

}

void test_dcfsnz_operand3_should_throw_error_with_W() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = W,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put W!\n");

 }

}

void test_dcfsnz_operand3_should_throw_error_with_F() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 0,

                    .operand3 = F,

                  };



 FSR[0xfE0] = 0xf;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot put F!\n");

 }

}

void test_dcfsnz_operand2_is_1_bsr_out_of_range_should_throw_error() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x34,

                    .operand2 = 1,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x1f;



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  dcfsnz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

  printf("Overed BSR range!\n");

 }

}











void test_dcfsnz_operand2_negative_one_and_operand3_negative_one_absoluteAddress_equal_zero() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };



 FSR[code.operand1] = 0x01;





 dcfsnz(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x101)), (_U_SINT)(_US16)((code.absoluteAddress)), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_HEX16);

}

void test_dcfsnz_operand2_negative_one_and_operand3_negative_one_absoluteAddress_not_equal_zero() {



  Instruction inst = {

                      .mnemonic = DCFSNZ,

                      .name = "dcfsnz"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };



 FSR[code.operand1] = 0x11;





 dcfsnz(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x102)), (_U_SINT)(_US16)((code.absoluteAddress)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_HEX16);

}
