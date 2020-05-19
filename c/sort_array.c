#include "sort_array.h"

void swap(Int_ptr, Int_ptr);

void swap(Int_ptr int_1, Int_ptr int_2)
{
  int temp = *int_1;
  *int_1 = *int_2;
  *int_2 = temp;
}

void selectionSort_array(Int_ptr array, int length)
{
  for (int i = 0; i < length - 1; i++) {
    int min_itm_idx = i;

    for (int j = i + 1; j < length; j++) {
      if (array[j] < array[min_itm_idx]) min_itm_idx = j;
    }

    swap(&array[i], &array[min_itm_idx]);
  }
}
