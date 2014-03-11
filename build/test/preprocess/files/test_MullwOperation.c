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

 int error;

 int overRange;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  mullw(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("Your file register is over ranged!\n");

  if (((overRange) != (error))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)26);;};

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
