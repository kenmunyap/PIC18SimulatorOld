#include "unity.h"
#include "TBLRDpostincf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_tblrdpostincf_should_pop_the_next_value() {



  Instruction inst = {

                      .mnemonic = TBLRD_post_increment,

                      .name = "tblrdpostincf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = -1,

                    .operand2 = -1,

                    .operand3 = -1,

     .absoluteAddress = 0x100

                  };



   FSR[0xFF8] = 0x00;

   FSR[0xFF7] = 0xA3;

   FSR[0xFF6] = 0x56;

   Table[0x00A356] = 0x55;

   Table[0x00A357] = 0x34;







 tblrdpostincf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x55)), (_U_SINT)(_US8 )((FSR[0xFF5])), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x00A357)), (_U_SINT)(_US32)((((FSR[0xFF8])<<16) + ((FSR[0xFF7])<<8) + (FSR[0xFF6]))), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x55)), (_U_SINT)(_US8 )((Table[(((FSR[0xFF8])<<16) + ((FSR[0xFF7])<<8) + (FSR[0xFF6]))])), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_HEX8);



}
