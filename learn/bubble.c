#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void printArray(int arr[], int arrlen);

int main(int argc, string argv[])
{
  int len = argc - 1;
  int numbers[len];

  for (int i = 1, j = 0; i < argc; i++)
  {
    numbers[j] = atoi(argv[i]);
    j += 1;
  }

  printArray(numbers, len);

  int swapped;
  int n = len;
  int temp;

  while (1)
  {
    swapped = 0;

    for (int i = 0; i < (n-1); i++)
    {
      if (numbers[i] > numbers[i+1])
      {
        temp = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = temp;
        swapped = 1;
      }
    }

    if (swapped == 0) break;
    printArray(numbers, len);
    n -= 1;
  }

  return 0;
}

void printArray(int arr[], int arrlen)
{
  printf("[");
  for (int i = 0; i < arrlen ; i++)
  {
    if (i == arrlen - 1)
    {
      printf("%i]\n", arr[i]);
      break;
    }
    printf("%i, ", arr[i]);
  }
}