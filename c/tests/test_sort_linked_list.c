#include <stdlib.h>
#include "run-c-tests/test.h"
#include "run-c-tests/assertions.h"
#include "sort_linked_list.h"

void add_to_list(LinkedList_ptr, Element);
LinkedList_ptr create_linked_list_from_ints(Int_ptr, int);
int is_int_less_than(Element, Element);
int is_int_equal(Element, Element);

void test_selectionSort_linked_list(TestReport_ptr);
Test_ptr should_s_sort_empty_linked_list(Test_ptr);
Test_ptr should_s_sort_sorted_linked_list(Test_ptr);
Test_ptr should_s_sort_unsorted_linked_list(Test_ptr);

void test_bubbleSort_array(TestReport_ptr);
Test_ptr should_b_sort_empty_array(Test_ptr);
Test_ptr should_b_sort_sorted_array(Test_ptr);
Test_ptr should_b_sort_unsorted_array(Test_ptr);

void test_insertionSort_array(TestReport_ptr);
Test_ptr should_i_sort_empty_array(Test_ptr);
Test_ptr should_i_sort_sorted_array(Test_ptr);
Test_ptr should_i_sort_unsorted_array(Test_ptr);

void add_to_list(LinkedList_ptr linked_list, Element element)
{
  Node_ptr node = malloc(sizeof(Node));
  node->element = element;
  node->prev = linked_list->last;
  node->next = NULL;

  Ptr_to_node_ptr ptr_to_set = &linked_list->first;

  if(linked_list->first != NULL)
  {
    ptr_to_set = &linked_list->last->next;
  }

  *ptr_to_set = node;
  linked_list->last = node;
  linked_list->length++;
}

LinkedList_ptr create_linked_list_from_ints(Int_ptr array, int length)
{
  LinkedList_ptr linked_list = malloc(sizeof(Linked_list));

  for(int i = 0; i < length; i++)
  {
    Element el = malloc(sizeof(int));
    *(Int_ptr)el = array[i];

    add_to_list(linked_list, el);
  }

  return linked_list;
}

int is_int_less_than(Element el_1, Element el_2)
{
  return *(Int_ptr)el_1 < *(Int_ptr)el_2;
}

int is_int_equal(Element el_1, Element el_2)
{
  return *(Int_ptr)el_1 == *(Int_ptr)el_2;
}

Test_ptr should_s_sort_empty_linked_list(Test_ptr test)
{
  test->name = "should sort empty linked_list";
  
  int array[] = {};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 0);
  LinkedList_ptr expected_ll = create_linked_list_from_ints(array, 0);

  selectionSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal, test);

  return test;
}

Test_ptr should_s_sort_sorted_linked_list(Test_ptr test)
{
  test->name = "should sort sorted linked_list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);
  LinkedList_ptr expected_ll = create_linked_list_from_ints(array, 5);

  selectionSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal,test);

  return test;
}

Test_ptr should_s_sort_unsorted_linked_list(Test_ptr test)
{
  test->name = "should sort unsorted linked_list";

  int array[] = {2, 1, 5, 3, 4};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  int sorted_array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr expected_ll = create_linked_list_from_ints(sorted_array, 5);

  selectionSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal, test);

  return test;
}

void test_selectionSort_linked_list(TestReport_ptr report)
{
  Test_Func tests[] = {
    should_s_sort_empty_linked_list,
    should_s_sort_sorted_linked_list,
    should_s_sort_unsorted_linked_list
  };

  run_tests("selectionSort_linked_list()", tests, 3, report);
}

Test_ptr should_b_sort_empty_linked_list(Test_ptr test)
{
  test->name = "should sort empty linked_list";
  
  int array[] = {};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 0);
  LinkedList_ptr expected_ll = create_linked_list_from_ints(array, 0);

  bubbleSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal, test);

  return test;
}

Test_ptr should_b_sort_sorted_linked_list(Test_ptr test)
{
  test->name = "should sort sorted linked_list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);
  LinkedList_ptr expected_ll = create_linked_list_from_ints(array, 5);

  bubbleSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal,test);

  return test;
}

Test_ptr should_b_sort_unsorted_linked_list(Test_ptr test)
{
  test->name = "should sort unsorted linked_list";

  int array[] = {2, 1, 5, 3, 4};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  int sorted_array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr expected_ll = create_linked_list_from_ints(sorted_array, 5);

  bubbleSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal, test);

  return test;
}

void test_bubbleSort_linked_list(TestReport_ptr report)
{
  Test_Func tests[] = {
    should_b_sort_empty_linked_list,
    should_b_sort_sorted_linked_list,
    should_b_sort_unsorted_linked_list
  };

  run_tests("bubbleSort_linked_list()", tests, 3, report);
}

Test_ptr should_i_sort_empty_linked_list(Test_ptr test)
{
  test->name = "should sort empty linked_list";
  
  int array[] = {};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 0);
  LinkedList_ptr expected_ll = create_linked_list_from_ints(array, 0);

  insertionSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal, test);

  return test;
}

Test_ptr should_i_sort_sorted_linked_list(Test_ptr test)
{
  test->name = "should sort sorted linked_list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);
  LinkedList_ptr expected_ll = create_linked_list_from_ints(array, 5);

  insertionSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal,test);

  return test;
}

Test_ptr should_i_sort_unsorted_linked_list(Test_ptr test)
{
  test->name = "should sort unsorted linked_list";

  int array[] = {2, 1, 5, 3, 4};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  int sorted_array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr expected_ll = create_linked_list_from_ints(sorted_array, 5);

  insertionSort_linked_list(linked_list, is_int_less_than);
  assert_linked_list_equal(linked_list, expected_ll, is_int_equal, test);

  return test;
}

void test_insertionSort_linked_list(TestReport_ptr report)
{
  Test_Func tests[] = {
    should_i_sort_empty_linked_list,
    should_i_sort_sorted_linked_list,
    should_i_sort_unsorted_linked_list
  };

  run_tests("insertionSort_linked_list()", tests, 3, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {
    test_selectionSort_linked_list,
    test_bubbleSort_linked_list,
    test_insertionSort_linked_list
  };

  TestReport_ptr report = runt_test_suites(test_suites, 3);
  display_report(report);
  
  return 0;
}
