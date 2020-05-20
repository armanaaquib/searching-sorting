#ifndef __TEST_H_
#define __TEST_H_

#define PASS "✅"
#define FAIL "❌"

typedef enum
{
  False,
  True
} Bool;

typedef char *Char_ptr;

typedef struct
{
  Char_ptr name;
  Bool status;
  Char_ptr error;
} Test;

typedef Test *Test_ptr;

typedef struct
{
  unsigned passed;
  unsigned failed;
} Test_Report;

typedef Test_Report *TestReport_ptr;

typedef Test_ptr (*Test_Func)(Test_ptr);
typedef void (*TestSuite_Func)(TestReport_ptr);

Test_ptr create_test(void);

void run_tests(Char_ptr, Test_Func [], int, TestReport_ptr);
TestReport_ptr runt_test_suites(TestSuite_Func [], int);

void display_report(TestReport_ptr);

#endif
