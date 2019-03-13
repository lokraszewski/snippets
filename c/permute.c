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
    print_arr(arr, ls);
  }
  else
  {
    for (int i = st; i < ls; i++)
    {
      swap(arr + st, arr + i);
      permute(arr, st + 1, ls);
      swap(arr + st, arr + i);
    }
  }
}

int main(int argc, char const* argv[])
{
  int arr[] = {0, 1, 2, 3};
  permute(arr, 0, 4);

  return 0;
}
