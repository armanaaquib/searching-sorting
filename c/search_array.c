#include "search_array.h"

int linear_search_array(Int_ptr array, int length, int searchKey)
{
  for (int i = 0; i < length; i++)
  {
    if (searchKey == array[i])
    {
      return i;
    }
  }

  return -1;
};
