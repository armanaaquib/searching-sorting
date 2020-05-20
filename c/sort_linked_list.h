#ifndef __SORT_LINKED_LIST_H_
#define __SORT_LINKED_LIST_H_

typedef void *Element;

typedef struct node
{
  Element element;
  struct node *prev;
  struct node *next;
} Node;

typedef Node *Node_ptr;
typedef Node_ptr *Ptr_to_node_ptr;

typedef struct
{
  Node_ptr first;
  Node_ptr last;
  int length;
} Linked_list;

typedef Linked_list *LinkedList_ptr;

typedef int (*Matcher)(Element, Element);

void selectionSort_linked_list(LinkedList_ptr, Matcher is_less_than);
void bubbleSort_linked_list(LinkedList_ptr, Matcher is_less_than);
void insertionSort_linked_list(LinkedList_ptr, Matcher is_less_than);

#endif
