#include "run-c-tests/test.h"
#include "run-c-tests/assertions.h"
#include "search_array.h"

void test_linear_search_array(TestReport_ptr);
Test_ptr should_search_empty_array(Test_ptr);
Test_ptr should_search_if_el_is_in_the_array(Test_ptr);
Test_ptr should_search_first_occurrence_el_is_in_the_array(Test_ptr);
Test_ptr should_search_if_el_is_not_in_the_array(Test_ptr);

Test_ptr should_search_empty_array(Test_ptr test)
{
  test->name = "should return -1 if array is empty";

  int array[] = {};

  assert_int_equal(linear_search_array(array, 5, 1), -1, test);

  return test;
}

Test_ptr should_search_if_el_is_in_the_array(Test_ptr test)
{
  test->name = "should return pos if element is in the array";

  int array[] = {1, 2, 3, 4, 5};

  assert_int_equal(linear_search_array(array, 5, 2), 1, test);

  return test;
}

Test_ptr should_search_first_occurrence_el_is_in_the_array(Test_ptr test)
{
  test->name = "should return pos of first occurrence if element is in the array";

  int array[] = {1, 2, 4, 4, 5};

  assert_int_equal(linear_search_array(array, 5, 4), 2, test);

  return test;
}

Test_ptr should_search_if_el_is_not_in_the_array(Test_ptr test)
{
  test->name = "should return -1 if element is not in the array";

  int array[] = {2, 1, 5, 3, 4};

  assert_int_equal(linear_search_array(array, 5, 6), -1, test);

  return test;
}

void test_linear_search_array(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_search_empty_array,
      should_search_if_el_is_in_the_array,
      should_search_first_occurrence_el_is_in_the_array,
      should_search_if_el_is_not_in_the_array};

  run_tests("linear_search_array()", tests, 4, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {test_linear_search_array};

  TestReport_ptr report = runt_test_suites(test_suites, 1);
  display_report(report);

  return 0;
}
