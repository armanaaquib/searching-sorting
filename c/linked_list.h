#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

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

#endif
