#include <stdio.h>
#include "assertions.h"

void assert_int_array_equal(Int_ptr array_1, Int_ptr array_2, int length, Test_ptr test)
{
  if(test->status == False) return;

  for(int i = 0; i < length; i++)
  {
    int actual = array_1[i];
    int expected = array_2[i];

    if(!(actual == expected))
    {
      test->status = False;
      sprintf(test->error, "Expected %d Actual %d\n", expected, actual);
      break;
    }
  }
}

void assert_linked_list_equal(LinkedList_ptr ll_1, LinkedList_ptr ll_2, Matcher is_el_equal, Test_ptr test)
{
  if(test->status == False) return;

  Bool is_equal = (ll_1->length == ll_2->length);

  if(!is_equal)
  {
    test->status = False;
    sprintf(test->error, "Expected length %d Actual length %d\n", ll_2->length, ll_1->length);
    return;
  }

  Node_ptr p_walk_1 = ll_1->first;
  Node_ptr p_walk_2 = ll_2->first;

  while(p_walk_1 != NULL)
  {
    is_equal = (*is_el_equal)(p_walk_1->element, p_walk_2->element);

    if(!is_equal)
    {
      test->status = False;
      sprintf(test->error, "Elements are not equal");
      break;
    }

    p_walk_1 = p_walk_1->next;
    p_walk_2 = p_walk_2->next;
  }
}
