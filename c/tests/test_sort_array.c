#include "test.h"
#include "assertions.h"
#include "sort_array.h"

void test_selectionSort_array(Report_ptr);
Test_ptr should_sort_empty_array();
Test_ptr should_sort_sorted_array();
Test_ptr should_sort_unsorted_array();

Test_ptr should_sort_empty_array()
{
  Test_ptr test = create_test("should sort empty array");
  
  int array[] = {};
  int expected[] = {};

  selectionSort_array(array, 0);
  assert_int_array_equal(array, expected, 0, test);

  return test;
}

Test_ptr should_sort_sorted_array()
{
  Test_ptr test = create_test("should sort empty array");

  int array[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};

  selectionSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

Test_ptr should_sort_unsorted_array()
{
  Test_ptr test = create_test("should sort empty array");

  int array[] = {2, 1, 5, 3, 4};
  int expected[] = {1, 2, 3, 4, 5};

  selectionSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

void test_selectionSort_array(Report_ptr report)
{
  Test_Func tests[] = {
    should_sort_empty_array,
    should_sort_sorted_array,
    should_sort_unsorted_array
  };

  run_tests("selectionSort_array()", tests, 3, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {test_selectionSort_array};

  Report_ptr report = runt_test_suites(test_suites, 1);

  return 0;
}
