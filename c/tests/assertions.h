#include "test.h"

#ifndef __ASSERTIONS_H_
#define __ASSERTIONS_H_

typedef int *Int_ptr;

// void assert_int_equal(int, int, Test_ptr);
void assert_int_array_equal(Int_ptr, Int_ptr, int, Test_ptr);

#endif
