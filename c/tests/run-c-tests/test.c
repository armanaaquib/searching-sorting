#include <stdio.h>
#include <stdlib.h>
#include "test.h"

TestReport_ptr create_report(void);
void pass_message(Char_ptr);
void fail_message(Char_ptr);
void error_message(Char_ptr);

Test_ptr create_test(void)
{
  Test_ptr test = malloc(sizeof(Test));

  test->status = True;
  test->error = malloc(sizeof(char) * 50);

  return test;
}

void pass_message(Char_ptr test_name)
{
  printf("  %s %s\n", PASS, test_name);
}

void fail_message(Char_ptr test_name)
{
  printf("  %s %s\n", FAIL, test_name);
}

void error_message(Char_ptr error)
{
  printf("\t%s\n", error);
}

void display_test_suite_name(Char_ptr test_suite_name)
{
  printf("\v%s\n", test_suite_name);
}

TestReport_ptr create_report(void)
{
  TestReport_ptr report = malloc(sizeof(Test_Report));

  report->passed = 0;
  report->failed = 0;

  return report;
}

void run_tests(Char_ptr test_suite_name, Test_Func tests[], int length, TestReport_ptr report)
{
  display_test_suite_name(test_suite_name);
  for (int i = 0; i < length; i++)
  {
    Test_ptr test = create_test();
    test = (*tests[i])(test);

    if (test->status)
    {
      report->passed++;
      pass_message(test->name);
    }
    else
    {
      report->failed++;
      fail_message(test->name);
      error_message(test->error);
    }
  }
}

TestReport_ptr runt_test_suites(TestSuite_Func test_suites[], int length)
{
  TestReport_ptr report = create_report();

  for (int i = 0; i < length; i++)
  {
    (*test_suites[i])(report);
  }

  return report;
}

void display_report(TestReport_ptr report)
{
  printf("\v%d Passing, %d Failing\n", report->passed, report->failed);
}
