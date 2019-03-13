#include <stdio.h>
#include <stdlib.h>

void swap(int* const x, int* const y)
{
  const int temp = *x;
  *x             = *y;
  *y             = temp;
}

void print_arr(int* arr, size_t sz)
{
  while (sz--) printf("%d ", *arr++);
  printf("\n");
}

void permute(int* arr, int st, int ls)
{
  if (st == ls)
  {
    // We have reached a possible permutation, print it for the user.
    print_arr(arr, ls);
  }
  else
  {
    for (int i = st; i < ls; i++)
    {
      swap(arr + st, arr + i);
      // Call this recursively skipping the start element. Eventually we will reach the termination condition (st == ls)
      permute(arr, st + 1, ls);
      // Swap back to restore the array to original version.
      swap(arr + st, arr + i);
    }
  }
}

int main(int argc, char const* argv[])
{
  int          arr[]    = {0, 1, 2, 3};
  const size_t arr_size = sizeof(arr) / sizeof(arr[0]);
  permute(arr, 0, arr_size);
  printf("Original: ");
  print_arr(arr, arr_size);

  return 0;
}
