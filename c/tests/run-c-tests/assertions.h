#include "test.h"
#include "../../linked_list.h"

#ifndef __ASSERTIONS_H_
#define __ASSERTIONS_H_

typedef int *Int_ptr;

void assert_int_equal(int, int, Test_ptr);
void assert_int_array_equal(Int_ptr, Int_ptr, int, Test_ptr);
void assert_element_equal(Element, Element, Matcher, Test_ptr);
void assert_element_null(Element, Test_ptr);
void assert_linked_list_equal(LinkedList_ptr, LinkedList_ptr, Matcher, Test_ptr);

#endif
