#include <stdio.h>
#include "sort_array.h"

void display_array(int array[], unsigned length)
{
  for(unsigned i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(void)
{
  int array[5] = {5,4,3,2,1};

  selectionSort_array(array, 5);
  display_array(array, 5);

  return 0;
}
