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

 errorException error;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((overRange)), (_U_SINT)((error)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

  printf("Your file register is over ranged!\n");

 }

}

void test_btg_operand2_select_bit_7_and_operand3_over_15_error(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = 1,

                  };



 FSR[0xfE0] = 0x1f;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 errorException bsrError;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { bsrError = CExceptionFrames[MY_ID].Exception; bsrError=bsrError; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((bsrRange)), (_U_SINT)((bsrError)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

  printf("Over BSR range!!\n");

 }

}

void test_btg_if_operand3_is_WREG_should_throw_error(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = W,

                  };



 FSR[0xfE0] = 0xf;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 errorException op3error;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { op3error = CExceptionFrames[MY_ID].Exception; op3error=op3error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((error_operand3)), (_U_SINT)((op3error)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot access WREG!!\n");

 }

}

void test_btg_if_operand3_is_File_should_throw_error(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = F,

                  };



 FSR[0xfE0] = 0xf;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 errorException op3error;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { op3error = CExceptionFrames[MY_ID].Exception; op3error=op3error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((error_operand3)), (_U_SINT)((op3error)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot access File!!\n");

 }

}

void test_btg_if_operand3_is_negative_two_should_throw_error(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = -2,

                  };



 FSR[0xfE0] = 0xf;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 errorException op3error;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { op3error = CExceptionFrames[MY_ID].Exception; op3error=op3error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((error_operand3)), (_U_SINT)((op3error)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot WREG    -2!!\n");

 }

}

void test_btg_if_operand3_is_negative_three_should_throw_error(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = -3,

                  };



 FSR[0xfE0] = 0xf;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 errorException op3error;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { op3error = CExceptionFrames[MY_ID].Exception; op3error=op3error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((error_operand3)), (_U_SINT)((op3error)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot access -3!!\n");

 }

}

void test_btg_if_operand3_is_default_should_not_throw_error(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = -3,

                  };



 FSR[0xfE0] = 0xf;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 errorException op3error;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  bitToggle(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { op3error = CExceptionFrames[MY_ID].Exception; op3error=op3error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((error_operand3)), (_U_SINT)((op3error)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

  printf("operand3 cannot access WREG!!\n");

 }

}











void test_btg_operand2_select_bit_zero_and_operand3_negative_one_operand1_overange_to_80(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x81,

                    .operand2 = 0,

                    .operand3 = -1,

                  };

 FSR[0xf81] =0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xf10)), (_U_SINT)(_US8 )((FSR[0xf81])), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x18)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x30)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x50)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)304, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)322, UNITY_DISPLAY_STYLE_HEX8);

}

void test_btg_operand2_select_bit_7_and_operand3_use_ACCESS_keyword(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = ACCESS,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)340, UNITY_DISPLAY_STYLE_HEX8);

}

void test_btg_operand2_select_bit_7_and_operand3_use_negative_four(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = -4,

                  };



 FSR[code.operand1]=0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)381, UNITY_DISPLAY_STYLE_HEX8);



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)401, UNITY_DISPLAY_STYLE_HEX8);



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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)421, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x18)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)440, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)459, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x30)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)478, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x50)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)497, UNITY_DISPLAY_STYLE_HEX8);

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

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)516, UNITY_DISPLAY_STYLE_HEX8);

}

void test_btg_operand2_select_bit_7_and_operand3_use_BANKED_keyword(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = BANKED,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)535, UNITY_DISPLAY_STYLE_HEX8);

}

void test_btg_operand2_select_bit_7_and_operand3_use_negative_five(){



  Instruction inst = {

                      .mnemonic = BTG,

                      .name = "btg"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x43,

                    .operand2 = 7,

                    .operand3 = -4,

                  };



 FSR[0xfE0] = 0x01;

 FSR[(FSR[0xfE0]<<8)+code.operand1] = 0x10;



 bitToggle(&code);



 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x90)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)554, UNITY_DISPLAY_STYLE_HEX8);

}
