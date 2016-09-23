/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
          return true;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int length = n;
    for (int i = 0; i < length; i++)
    {
      printf("%i ", values[i]);
    }
    // TODO: implement an O(n^2) sorting algorithm
    int swapped;
    int temp;
    
    while (1)
    {
      swapped = 0;
      
      for (int i = 0; i < (n-1); i++)
      {
        if (values[i] > values[i+1])
        {
          temp = values[i];
          values[i] = values[i + 1];
          values[i + 1] = temp;
          swapped = 1;
        }
      }
      
      if (swapped == 0) break;
      n -= 1;
    }
    printf("\n");
    for (int i = 0; i < length; i++)
    {
      printf("%i ", values[i]);
    }
    
    return;
}
