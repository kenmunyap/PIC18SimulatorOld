#include "unity.h"
#include "Bytecode.h"
#include "BitToggle.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

/*
	checking error
*/

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
	errorException error;
	Try{
		bitToggle(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(overRange,error);
		printf("Your file register is over ranged!\n");
	}
}
void test_btg_operand2_select_bit_7_and_operand3_over_15_error(){
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
				  
	FSR[BSR] = 0x1f;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	errorException bsrError;
	
	Try{
		bitToggle(&code);
	}Catch(bsrError){
		TEST_ASSERT_EQUAL(bsrRange,bsrError);
		printf("Over BSR range!!\n");
	}  
}
void test_btg_if_operand3_is_WREG_should_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = W,					
                  };
				  
	FSR[BSR] = 0xf;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	errorException op3error;
	
	Try{
		bitToggle(&code);
	}Catch(op3error){
		TEST_ASSERT_EQUAL(error_operand3,op3error);
		printf("operand3 cannot access WREG!!\n");
	}  
}
void test_btg_if_operand3_is_File_should_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = F,					
                  };
				  
	FSR[BSR] = 0xf;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	errorException op3error;
	
	Try{
		bitToggle(&code);
	}Catch(op3error){
		TEST_ASSERT_EQUAL(error_operand3,op3error);
		printf("operand3 cannot access File!!\n");
	}  
}
void test_btg_if_operand3_is_negative_two_should_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	 7, 	  // this is select which case need to be toggle;
                    .operand3 = -2,					
                  };
				  
	FSR[BSR] = 0xf;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	errorException op3error;
	
	Try{
		bitToggle(&code);
	}Catch(op3error){
		TEST_ASSERT_EQUAL(error_operand3,op3error);
		printf("operand3 cannot WREG    -2!!\n");
	}  
}
void test_btg_if_operand3_is_negative_three_should_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	 7, 	  // this is select which case need to be toggle;
                    .operand3 = -3,					
                  };
				  
	FSR[BSR] = 0xf;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	errorException op3error;
	
	Try{
		bitToggle(&code);
	}Catch(op3error){
		TEST_ASSERT_EQUAL(error_operand3,op3error);
		printf("operand3 cannot access -3!!\n");
	}  
}
void test_btg_if_operand3_is_default_should_not_throw_error(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	 7, 	  // this is select which case need to be toggle;
                    .operand3 = -3,					
                  };
				  
	FSR[BSR] = 0xf;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	errorException op3error;
	
	Try{
		bitToggle(&code);
	}Catch(op3error){
		TEST_ASSERT_EQUAL(error_operand3,op3error);
		printf("operand3 cannot access WREG!!\n");
	}  
}

/*
	select access file register
*/

void test_btg_operand2_select_bit_zero_and_operand3_negative_one_operand1_overange_to_80(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x81,  
                    .operand2 =	 0, 	  
                    .operand3 = -1,					
                  };
	FSR[0xf81] =0x10;	  

	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x11,FSR[0xf81]);  
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
void test_btg_operand2_select_bit_7_and_operand3_use_ACCESS_keyword(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	7, 	  
                    .operand3 = ACCESS,					
                  };
				  
	FSR[code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[code.operand1]);  
}
void test_btg_operand2_select_bit_7_and_operand3_use_negative_four(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  
                    .operand2 =	7, 	  
                    .operand3 = -4,					
                  };
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1]=0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[0x143]);  
}

/*
 select bank register
 */
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

	TEST_ASSERT_EQUAL_HEX8(0x11,FSR[0x143]);
  
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

	TEST_ASSERT_EQUAL_HEX8(0x12,FSR[0x143]);
  
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

	TEST_ASSERT_EQUAL_HEX8(0x14,FSR[0x143]);
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

	TEST_ASSERT_EQUAL_HEX8(0x18,FSR[0x143]);  
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

	TEST_ASSERT_EQUAL_HEX8(0x00,FSR[0x143]); 
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

	TEST_ASSERT_EQUAL_HEX8(0x30,FSR[0x143]); 
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

	TEST_ASSERT_EQUAL_HEX8(0x50,FSR[0x143]);  
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
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[0x143]);
}
void test_btg_operand2_select_bit_7_and_operand3_use_BANKED_keyword(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = BANKED,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[0x143]);
}
void test_btg_operand2_select_bit_7_and_operand3_use_negative_five(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = BTG,
                      .name = "btg"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 =	0x43,  //address of file select register
                    .operand2 =	7, 	  // this is select which case need to be toggle;
                    .operand3 = -4,					
                  };
				  
	FSR[BSR] = 0x01;			  
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x10;
	
	bitToggle(&code);

	TEST_ASSERT_EQUAL_HEX8(0x90,FSR[0x143]);
}



