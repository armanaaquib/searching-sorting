#include <stdlib.h>
#include "sort_linked_list.h"

void swap_element(Node_ptr, Node_ptr);
void _quickSort_linked_list(Node_ptr, Node_ptr, Matcher);

void swap_element(Node_ptr node_1, Node_ptr node_2)
{
  Element temp = node_1->element;
  node_1->element = node_2->element;
  node_2->element = temp;
}

void selectionSort_linked_list(LinkedList_ptr linked_list, Matcher is_less_than)
{
  Node_ptr p_walk = linked_list->first;

  while (p_walk != NULL)
  {
    Node_ptr min_node = p_walk;
    Node_ptr i_p_walk = p_walk->next;

    while (i_p_walk != NULL)
    {
      if ((*is_less_than)(i_p_walk->element, min_node->element))
        min_node = i_p_walk;

      i_p_walk = i_p_walk->next;
    }

    swap_element(p_walk, min_node);
    p_walk = p_walk->next;
  }
}

void bubbleSort_linked_list(LinkedList_ptr linked_list, Matcher is_less_than)
{
  Node_ptr p_walk = linked_list->first;

  while (p_walk != NULL)
  {
    int swap_status = 0;
    Node_ptr i_p_walk = p_walk->next;

    while (i_p_walk != NULL)
    {
      if ((*is_less_than)(i_p_walk->element, i_p_walk->prev->element))
      {
        swap_element(i_p_walk, i_p_walk->prev);
        swap_status = 1;
      }

      i_p_walk = i_p_walk->next;
    }

    if (swap_status == 0)
      break;

    p_walk = p_walk->next;
  }
}

void insertionSort_linked_list(LinkedList_ptr linked_list, Matcher is_less_than)
{
  Node_ptr p_walk = linked_list->first;

  while (p_walk != NULL)
  {
    Element key_el = p_walk->element;
    Node_ptr i_p_walk = p_walk->prev;

    while (i_p_walk && (*is_less_than)(key_el, i_p_walk->element))
    {
      i_p_walk->next->element = i_p_walk->element;
      i_p_walk = i_p_walk->prev;
    }

    if (i_p_walk == NULL)
    {
      linked_list->first->element = key_el;
    }
    else
    {
      i_p_walk->next->element = key_el;
    }

    p_walk = p_walk->next;
  }
}

// Lomuto partition scheme
void _quickSort_linked_list(Node_ptr start, Node_ptr end, Matcher sorter)
{
  if (!start || !end || start == end || start == end->next)
    return;

  Node_ptr pivot = end;
  Node_ptr last_smaller = start;

  for (Node_ptr p_walk = start; p_walk != end; p_walk = p_walk->next)
  {
    if (sorter(p_walk->element, pivot->element))
    {
      swap_element(p_walk, last_smaller);
      last_smaller = last_smaller == NULL ? last_smaller : last_smaller->next;
    }
  }
  swap_element(last_smaller, pivot);
  pivot = last_smaller;

  _quickSort_linked_list(start, pivot->prev, sorter);
  _quickSort_linked_list(pivot->next, end, sorter);
}

void quickSort_linked_list(LinkedList_ptr linked_list, Matcher sorter)
{
  _quickSort_linked_list(linked_list->first, linked_list->last, sorter);
}
