#include "unity.h"
#include "Mullw.h"
#include "CException.h"
#include "Bytecode.h"
void setUp() {}

void tearDown() {}



void test_mullw_operand1_is_over_0_or_255(){



  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

                    .operand2 = 0,

                    .operand3 = 0,

                  };

 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  mullw(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((overRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

  printf("Your file register is over ranged!\n");

 }

}



void test_mullw_store_into_PRODH_and_PRODL(){





  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xC4,

                    .operand2 = -1,

                    .operand3 =-1,

                  };





 FSR[0xFE8] = 0xE2;

 mullw(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xAD)), (_U_SINT)(_US8 )((FSR[0xFF4])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x08)), (_U_SINT)(_US8 )((FSR[0xFF3])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX8);

}



void test_mullw_operand3_is_not_close_throw_error(){





  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xC4,

                    .operand2 = -1,

                    .operand3 = 0,

                  };





 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  mullw(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_3error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 got value!\n");

 }

}



void test_mullw_operand2_is_not_close_throw_error(){





  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xC4,

                    .operand2 = 0,

                    .operand3 = -1,

                  };





 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  mullw(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_2error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 got value!\n");

 }

}



void test_mullw_operand2_and_operand3_is_not_close_throw_error(){





  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xC4,

                    .operand2 = 0,

                    .operand3 = 0,

                  };





 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  mullw(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

  printf("operand2 and 3 got value!\n");

 }

}
