#include "unity.h"
#include "Mullw.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_bitToggle_the_last_bit_need_to_toggle() {



  Instruction inst = {

                      .mnemonic = MULLW,

                      .name = "mullw"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xC4,

                    .operand2 = -1,

                    .operand3 = -1,

                  };



 FSR[0xf8b] = 0xE2;



 mullw(&code);





}
