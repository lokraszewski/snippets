#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  srand(time(NULL));

  for (size_t i = 0; i < argc; i++) printf("%s\n", argv[i]);

  size_t arr_size = 4;
  if (argc >= 2)
    arr_size = atoi(argv[1]);

  printf("create array of size: %zu : ", arr_size);

  int* array = malloc(arr_size);

  if (array == NULL)
  {
    printf("ERROR: out of memory");
    return -1;
  }

  for (size_t i = 0; i < arr_size; i++) array[i] = rand();

  print_arr(array, arr_size);
  permute(array, 0, arr_size);

  free(array);

  return 0;
}
