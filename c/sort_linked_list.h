#include "linked_list.h"

#ifndef __SORT_LINKED_LIST_H_
#define __SORT_LINKED_LIST_H_

void selectionSort_linked_list(LinkedList_ptr, Matcher is_less_than);
void bubbleSort_linked_list(LinkedList_ptr, Matcher is_less_than);
void insertionSort_linked_list(LinkedList_ptr, Matcher is_less_than);
void quickSort_linked_list(LinkedList_ptr, Matcher sorter);

#endif
