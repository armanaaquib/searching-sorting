#include <stdlib.h>
#include "search_linked_list.h"

Node_ptr get_mid(Node_ptr start, Node_ptr end);
Element _binarySearch(Node_ptr start, Node_ptr end, Element search_key, Matcher matcher);

int linear_search_linked_list(LinkedList_ptr linked_list, Element search_key, Matcher matcher)
{
  int pos = 0;
  for (Node_ptr p_walk = linked_list->first; p_walk != NULL; p_walk = p_walk->next)
  {
    if ((*matcher)(search_key, p_walk->element))
    {
      return pos;
    }
    pos++;
  }

  return -1;
};

Node_ptr get_mid(Node_ptr start, Node_ptr end)
{
  Node_ptr mid = start;
  Node_ptr last = start;

  while (last != end)
  {
    last = last->next;

    if (last != end)
    {
      mid = mid->next;
      last = last->next;
    }
  }

  return mid;
}

Element _binarySearch(Node_ptr start, Node_ptr end, Element search_key, Matcher matcher)
{
  if (!end || end->next == start)
  {
    return NULL;
  }

  Node_ptr mid = get_mid(start, end);

  if ((*matcher)(search_key, mid->element) == 0)
  {
    return mid->element;
  }

  if ((*matcher)(search_key, mid->element) < 0)
  {
    return _binarySearch(start, mid->prev, search_key, matcher);
  }

  return _binarySearch(mid->next, end, search_key, matcher);
};

Element binary_search_linked_list(LinkedList_ptr linked_list, Element search_key, Matcher matcher)
{
  return _binarySearch(linked_list->first, linked_list->last, search_key, matcher);
};
