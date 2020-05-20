#include <stdlib.h>
#include "sort_linked_list.h"

void swap_element(Node_ptr, Node_ptr);

void swap_element(Node_ptr node_1, Node_ptr node_2)
{
  Element temp = node_1->element;
  node_1->element = node_2->element;
  node_2->element = temp;
}

void selectionSort_linked_list(LinkedList_ptr linked_list, Matcher less_than)
{
  Node_ptr p_walk = linked_list->first;

  while(p_walk != NULL)
  {
    Node_ptr min_node = p_walk;
    Node_ptr i_p_walk = p_walk->next;

    while(i_p_walk != NULL)
    {
      if ((*less_than)(i_p_walk->element, min_node->element))
        min_node = i_p_walk;
      
      i_p_walk = i_p_walk->next;
    }

    swap_element(p_walk, min_node);
    p_walk = p_walk->next;
  }
}
