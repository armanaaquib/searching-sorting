#include <stdlib.h>
#include "run-c-tests/test.h"
#include "run-c-tests/assertions.h"
#include "search_linked_list.h"

void add_to_list(LinkedList_ptr, Element);
LinkedList_ptr create_linked_list_from_ints(Int_ptr, int);
int is_int_equal(Element, Element);
int cmp_int(Element, Element);

void test_linear_search_linked_list(TestReport_ptr);
Test_ptr should_l_search_empty_linked_list(Test_ptr);
Test_ptr should_l_search_if_el_is_in_the_linked_list(Test_ptr);
Test_ptr should_l_search_first_occurrence_el_is_in_the_linked_list(Test_ptr);
Test_ptr should_l_search_if_el_is_not_in_the_linked_list(Test_ptr);

void test_binary_search_linked_list(TestReport_ptr);
Test_ptr should_b_search_empty_linked_list(Test_ptr);
Test_ptr should_b_search_if_el_is_in_the_left_of_the_linked_list(Test_ptr);
Test_ptr should_b_search_if_el_is_in_the_right_of_the_linked_list(Test_ptr);
Test_ptr should_b_search_if_el_is_not_in_the_linked_list(Test_ptr);

void add_to_list(LinkedList_ptr linked_list, Element element)
{
  Node_ptr node = malloc(sizeof(Node));
  node->element = element;
  node->prev = linked_list->last;
  node->next = NULL;

  Ptr_to_node_ptr ptr_to_set = &linked_list->first;

  if (linked_list->first != NULL)
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
  linked_list->first = NULL;
  linked_list->last = NULL;
  linked_list->length = 0;

  for (int i = 0; i < length; i++)
  {
    Element el = malloc(sizeof(int));
    *(Int_ptr)el = array[i];

    add_to_list(linked_list, el);
  }
  return linked_list;
}

int is_int_equal(Element el_1, Element el_2)
{
  return *(Int_ptr)el_1 == *(Int_ptr)el_2;
}

int cmp_int(Element el_1, Element el_2)
{
  return *(Int_ptr)el_1 - *(Int_ptr)el_2;
}

Test_ptr should_l_search_empty_linked_list(Test_ptr test)
{
  test->name = "should return -1 if linked list is empty";

  int array[] = {};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 0);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 1;
  assert_int_equal(linear_search_linked_list(linked_list, element, is_int_equal), -1, test);

  return test;
}

Test_ptr should_l_search_if_el_is_in_the_linked_list(Test_ptr test)
{
  test->name = "should return pos if element is in the linked list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 2;
  assert_int_equal(linear_search_linked_list(linked_list, element, is_int_equal), 1, test);

  return test;
}

Test_ptr should_l_search_first_occurrence_el_is_in_the_linked_list(Test_ptr test)
{
  test->name = "should return pos of first occurrence if element is in the linked list";

  int array[] = {1, 3, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 3;
  assert_int_equal(linear_search_linked_list(linked_list, element, is_int_equal), 1, test);

  return test;
}

Test_ptr should_l_search_if_el_is_not_in_the_linked_list(Test_ptr test)
{
  test->name = "should return -1 if element is not in the linked list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 6;
  assert_int_equal(linear_search_linked_list(linked_list, element, is_int_equal), -1, test);

  return test;
}

void test_linear_search_linked_list(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_l_search_empty_linked_list,
      should_l_search_if_el_is_in_the_linked_list,
      should_l_search_first_occurrence_el_is_in_the_linked_list,
      should_l_search_if_el_is_not_in_the_linked_list};

  run_tests("linear_search_array()", tests, 4, report);
}

Test_ptr should_b_search_empty_linked_list(Test_ptr test)
{
  test->name = "should return NULL if linked list is empty";

  int array[] = {};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 0);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 1;
  assert_element_null(binary_search_linked_list(linked_list, element, cmp_int), test);

  return test;
}

Test_ptr should_b_search_if_el_is_in_the_right_of_the_linked_list(Test_ptr test)
{
  test->name = "should return pos if element is in the right of the linked list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 5;
  assert_element_equal(binary_search_linked_list(linked_list, element, cmp_int), element, is_int_equal, test);

  return test;
}

Test_ptr should_b_search_if_el_is_in_the_left_of_the_linked_list(Test_ptr test)
{
  test->name = "should return pos if element is in the left of the linked list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 1;
  assert_element_equal(binary_search_linked_list(linked_list, element, cmp_int), element, is_int_equal, test);

  return test;
}

Test_ptr should_b_search_if_el_is_not_in_the_linked_list(Test_ptr test)
{
  test->name = "should return NULL if element is not in the linked list";

  int array[] = {1, 2, 3, 4, 5};
  LinkedList_ptr linked_list = create_linked_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  *(Int_ptr)element = 6;
  assert_element_null(binary_search_linked_list(linked_list, element, cmp_int), test);

  return test;
}

void test_binary_search_linked_list(TestReport_ptr report)
{
  Test_Func tests[] = {
      should_b_search_empty_linked_list,
      should_b_search_if_el_is_in_the_left_of_the_linked_list,
      should_b_search_if_el_is_in_the_right_of_the_linked_list,
      should_b_search_if_el_is_not_in_the_linked_list};

  run_tests("binary_search_array()", tests, 4, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {test_linear_search_linked_list, test_binary_search_linked_list};

  TestReport_ptr report = runt_test_suites(test_suites, 2);
  display_report(report);

  return 0;
}
