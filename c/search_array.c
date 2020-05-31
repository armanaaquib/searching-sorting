#include "search_array.h"

int _binarySearch(Int_ptr, int, int, int);

int linear_search_array(Int_ptr array, int length, int search_key)
{
  for (int i = 0; i < length; i++)
  {
    if (search_key == array[i])
    {
      return i;
    }
  }

  return -1;
};

int _binarySearch(Int_ptr array, int start, int end, int search_key)
{
  if (end < start)
  {
    return -1;
  }

  int midIdx = (start + end) / 2;

  if (search_key == array[midIdx])
  {
    return midIdx;
  }

  if (search_key < array[midIdx])
  {
    return _binarySearch(array, start, midIdx - 1, search_key);
  }

  return _binarySearch(array, midIdx + 1, end, search_key);
};

int binary_search_array(Int_ptr array, int length, int search_key)
{
  return _binarySearch(array, 0, length - 1, search_key);
};
