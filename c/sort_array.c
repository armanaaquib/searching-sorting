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
  for (int i = 0; i < length - 1; i++) 
  {
    int min_itm_idx = i;

    for (int j = i + 1; j < length; j++) 
    {
      if (array[j] < array[min_itm_idx]) 
        min_itm_idx = j;
    }

    swap(&array[i], &array[min_itm_idx]);
  }
}

void bubbleSort_array(Int_ptr array, int length)
{
  for (int i = 0; i < length - 1; i++)
  {
    int swap_status = 0;
    
    for (int j = i; j < length - i - 1; j++)
    {
      if (array[j] > array[j+1])
      {
        swap(&array[j], &array[j+1]);
        swap_status = 1;
      }
    }

    if(swap_status == 0)
      break;
  }
}

void insertionSort_array(Int_ptr array, int length)
{
  for (int i = 1; i < length; i++)
  {
    int key = array[i];

    int j = i - 1;
    while (j >= 0 && key < array[j])
    {
      array[j + 1] = array[j];
      j -= 1;
    }

    array[j + 1] = key;
  }
}