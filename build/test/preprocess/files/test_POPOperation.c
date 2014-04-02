#include "unity.h"
#include "POP.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_pop_should_pop_the_next_value() {



  Instruction inst = {

                      .mnemonic = POP,

                      .name = "pop"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = -1,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };

 FSR[0xFFC] = 10;

 PIC18Stack[10] = 0x0031A2;

 PIC18Stack[9] = 0x014332;



 pop(&code);



 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((FSR[0xFFC])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x0031A2)), (_U_SINT)(_US32)((PC)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[0xFFF])), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x43)), (_U_SINT)(_US8 )((FSR[0xFFE])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x32)), (_U_SINT)(_US8 )((FSR[0xFFD])), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_HEX8);

}



void test_pop_operand1_is_not_off(){



 Instruction inst = {

                      .mnemonic = POP,

                      .name = "pop"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x11,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };



 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  pop(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

 }

}
