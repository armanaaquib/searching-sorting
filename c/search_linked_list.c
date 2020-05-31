#include <stdlib.h>
#include "search_linked_list.h"

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
