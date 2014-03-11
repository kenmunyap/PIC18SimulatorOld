#include "unity.h"
#include "Bytecode.h"
#include "BitToggle.h"
#include "CException.h"
void setUp() {}
void tearDown() {}


void test_btg_operand1_is_over_0_or_255(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0xfff,  
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
	int error;
	int overRange;
	Try{
		bitToggle(&code);
	}Catch(error){
		printf("Your file register is over ranged!\n");
		TEST_ASSERT_NOT_EQUAL(overRange,error);
	}
}

void test_btg_operand2_select_bit_0_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	0, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x11,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_1_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	1, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x12,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_3_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	3, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x18,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_4_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	4, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_5_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	5, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x30,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_6_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	6, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x50,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_7_and_operand3_0_access_bank(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	7, 	  
                    .operand3 = 0,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_0_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	0, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x11,FSR[code.operand1]);
  
}


void test_btg_operand2_select_bit_1_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	1, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x12,FSR[code.operand1]);
  
}

void test_btg_operand2_select_bit_2_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	2, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x14,FSR[code.operand1]);
}

void test_btg_operand2_select_bit_3_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	3, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x18,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_4_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	4, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[code.operand1]); 
}

void test_btg_operand2_select_bit_5_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	5, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x30,FSR[code.operand1]); 
}

void test_btg_operand2_select_bit_6_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	6, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x50,FSR[code.operand1]);  
}

void test_btg_operand2_select_bit_7_and_operand3_1_bank_selecter_register(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = 1,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[code.operand1]);
  
}

