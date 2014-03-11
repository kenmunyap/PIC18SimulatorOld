#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "BitToggle.h"
void setUp() {}

void tearDown() {}





void test_btg_operand1_is_over_0_or_255(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

                    .operand2 = 0,

                    .operand3 = 0,

                  };

 int error;

 int overRange;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("Your file register is over ranged!\n");

  if (((overRange) != (error))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)26);;};

 }

}



void test_btg_operand2_select_bit_0_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 0,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_1_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 1,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_3_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 3,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x18)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_4_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 4,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_5_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 5,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x30)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_6_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 6,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x50)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_7_and_operand3_0_access_bank(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = 0,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_0_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 0,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_HEX8);



}





void test_btg_operand2_select_bit_1_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 1,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_HEX8);



}



void test_btg_operand2_select_bit_2_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 2,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_3_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 3,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x18)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_4_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 4,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_5_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 5,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x30)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)283, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_6_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 6,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x50)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_HEX8);

}



void test_btg_operand2_select_bit_7_and_operand3_1_bank_selecter_register(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)323, UNITY_DISPLAY_STYLE_HEX8);



}
