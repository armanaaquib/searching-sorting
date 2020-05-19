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
