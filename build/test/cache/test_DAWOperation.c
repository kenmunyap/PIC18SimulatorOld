#include "unity.h"
#include "dAW.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_daw_all_operand_is_negative_one(){



  Instruction inst = {

                      .mnemonic = DAW,

                      .name = "daw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = -1,

                    .operand2 = -1,

                    .operand3 = -1,

                  };





 FSR[0xf8b] = 0xA5;

 FSR[0xfd8] = 0x02;

 daw(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x05)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX8);

}



void test_daw_all_operand_is_not_negative_one(){



  Instruction inst = {

                      .mnemonic = DAW,

                      .name = "daw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x10,

                    .operand2 = -1,

                    .operand3 = -1,

                  };



 errorException error;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  daw(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((op_error)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 }



}
