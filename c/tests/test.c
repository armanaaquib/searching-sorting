#include <stdio.h>
#include <stdlib.h>
#include "test.h"

Report_ptr create_report(void);
void pass_message(Char_ptr);
void fail_message(Char_ptr);
void error_message(Char_ptr);

Test_ptr create_test(Char_ptr name)
{
  Test_ptr test = malloc(sizeof(Test));

  test->name = name;
  test->status = True;
  test->error = malloc(sizeof(char) * 50);

  return test;
}

void pass_message(Char_ptr test_name)
{
  printf("%s %s\n", PASS, test_name);
}

void fail_message(Char_ptr test_name)
{
  printf("%s %s\n", FAIL, test_name);
}

void error_message(Char_ptr error)
{
  printf("%s\n", error);
}

void display_test_suite_name(Char_ptr test_suite_name)
{
  printf("%s\n", test_suite_name);
}

Report_ptr create_report(void)
{
  Report_ptr report = malloc(sizeof(Report));

  report->total = 0;
  report->passed = 0;
  report->failed = 0;

  return report;
}

void run_tests(Char_ptr test_suite_name, Test_Func tests[], int length, Report_ptr report)
{
  display_test_suite_name(test_suite_name);

  for(int i = 0; i < length; i++)
  {
    report->total++;

    Test_ptr test = (*tests[i])();

    if(test->status)
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

Report_ptr runt_test_suites(TestSuite_Func test_suites[], int length)
{
  Report_ptr report = create_report();

  for(int i = 0; i < length; i++)
  {
    (*test_suites[i])(report);
  }

  return report;
}

void display_report(Report_ptr report)
{
  printf("\nTotal: %d\n", report->total);
  printf("Passed: %d, Failed: %d\n", report->passed, report->failed);
}
