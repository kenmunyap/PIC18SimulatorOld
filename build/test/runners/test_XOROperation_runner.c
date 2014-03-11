/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_xorwf_file_over_0_or_255(void);
extern void test_xorwf_operand2_0_in_wreg_and_operand3_0_access_bank(void);
extern void test_xorwf_operand2_1_in_wreg_and_operand3_0_access_bank(void);
extern void test_xorwf_operand2_0_in_wreg_and_operand3_1_access_bank(void);
extern void test_xorwf_operand2_1_in_wreg_and_operand3_1_access_bank(void);
extern void test_xorwf_bsr_over_15(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_XOROperation.c";
  UnityBegin();
  RUN_TEST(test_xorwf_file_over_0_or_255, 9);
  RUN_TEST(test_xorwf_operand2_0_in_wreg_and_operand3_0_access_bank, 31);
  RUN_TEST(test_xorwf_operand2_1_in_wreg_and_operand3_0_access_bank, 51);
  RUN_TEST(test_xorwf_operand2_0_in_wreg_and_operand3_1_access_bank, 71);
  RUN_TEST(test_xorwf_operand2_1_in_wreg_and_operand3_1_access_bank, 90);
  RUN_TEST(test_xorwf_bsr_over_15, 110);

  return (UnityEnd());
}
