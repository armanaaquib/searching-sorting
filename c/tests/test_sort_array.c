#include "run-c-tests/test.h"
#include "run-c-tests/assertions.h"
#include "sort_array.h"

void test_selectionSort_array(TestReport_ptr);
Test_ptr should_s_sort_empty_array(Test_ptr);
Test_ptr should_s_sort_sorted_array(Test_ptr);
Test_ptr should_s_sort_unsorted_array(Test_ptr);

void test_bubbleSort_array(TestReport_ptr);
Test_ptr should_b_sort_empty_array(Test_ptr);
Test_ptr should_b_sort_sorted_array(Test_ptr);
Test_ptr should_b_sort_unsorted_array(Test_ptr);

void test_insertionSort_array(TestReport_ptr);
Test_ptr should_i_sort_empty_array(Test_ptr);
Test_ptr should_i_sort_sorted_array(Test_ptr);
Test_ptr should_i_sort_unsorted_array(Test_ptr);

void test_quickSort_array(TestReport_ptr);
Test_ptr should_q_sort_empty_array(Test_ptr);
Test_ptr should_q_sort_sorted_array(Test_ptr);
Test_ptr should_q_sort_unsorted_array(Test_ptr);

Test_ptr should_s_sort_empty_array(Test_ptr test)
{
  test->name = "should sort empty array";

  int array[] = {};
  int expected[] = {};

  selectionSort_array(array, 0);
  assert_int_array_equal(array, expected, 0, test);

  return test;
}

Test_ptr should_s_sort_sorted_array(Test_ptr test)
{
  test->name = "should sort sorted array";

  int array[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};

  selectionSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

Test_ptr should_s_sort_unsorted_array(Test_ptr test)
{
  test->name = "should sort unsorted array";

  int array[] = {2, 1, 5, 3, 4};
  int expected[] = {1, 2, 3, 4, 5};

  selectionSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

void test_selectionSort_array(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_s_sort_empty_array,
      should_s_sort_sorted_array,
      should_s_sort_unsorted_array};

  run_tests("selectionSort_array()", tests, 3, report);
}

Test_ptr should_b_sort_empty_array(Test_ptr test)
{
  test->name = "should sort empty array";

  int array[] = {};
  int expected[] = {};

  bubbleSort_array(array, 0);
  assert_int_array_equal(array, expected, 0, test);

  return test;
}

Test_ptr should_b_sort_sorted_array(Test_ptr test)
{
  test->name = "should sort sorted array";

  int array[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};

  bubbleSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

Test_ptr should_b_sort_unsorted_array(Test_ptr test)
{
  test->name = "should sort unsorted array";

  int array[] = {2, 1, 5, 3, 4};
  int expected[] = {1, 2, 3, 4, 5};

  bubbleSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

void test_bubbleSort_array(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_b_sort_empty_array,
      should_b_sort_sorted_array,
      should_b_sort_unsorted_array};

  run_tests("bubbleSort_array()", tests, 3, report);
}

Test_ptr should_i_sort_empty_array(Test_ptr test)
{
  test->name = "should sort empty array";

  int array[] = {};
  int expected[] = {};

  insertionSort_array(array, 0);
  assert_int_array_equal(array, expected, 0, test);

  return test;
}

Test_ptr should_i_sort_sorted_array(Test_ptr test)
{
  test->name = "should sort sorted array";

  int array[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};

  insertionSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

Test_ptr should_i_sort_unsorted_array(Test_ptr test)
{
  test->name = "should sort unsorted array";

  int array[] = {2, 1, 5, 3, 4};
  int expected[] = {1, 2, 3, 4, 5};

  insertionSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

void test_insertionSort_array(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_i_sort_empty_array,
      should_i_sort_sorted_array,
      should_i_sort_unsorted_array};

  run_tests("insertionSort_array()", tests, 3, report);
}

Test_ptr should_q_sort_empty_array(Test_ptr test)
{
  test->name = "should sort empty array";

  int array[] = {};
  int expected[] = {};

  quickSort_array(array, 0);
  assert_int_array_equal(array, expected, 0, test);

  return test;
}

Test_ptr should_q_sort_sorted_array(Test_ptr test)
{
  test->name = "should sort sorted array";

  int array[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};

  quickSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

Test_ptr should_q_sort_unsorted_array(Test_ptr test)
{
  test->name = "should sort unsorted array";

  int array[] = {2, 1, 5, 3, 4};
  int expected[] = {1, 2, 3, 4, 5};

  quickSort_array(array, 5);
  assert_int_array_equal(array, expected, 5, test);

  return test;
}

void test_quickSort_array(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_q_sort_empty_array,
      should_q_sort_sorted_array,
      should_q_sort_unsorted_array};

  run_tests("quickSort_array()", tests, 3, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {
      test_selectionSort_array,
      test_bubbleSort_array,
      test_insertionSort_array,
      test_quickSort_array};

  TestReport_ptr report = runt_test_suites(test_suites, 4);
  display_report(report);

  return 0;
}
