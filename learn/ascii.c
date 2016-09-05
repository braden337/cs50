#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  printf("Uppercase\n");
  for (int i = 65, n = i + 26; i < n; ++i)
  {
    printf("%c: %i\n", (char) i, i);
  }

  printf("\nLowercase\n");
  for (int i = 97, n = i + 26; i < n; ++i)
  {
    printf("%c: %3i\n", (char) i, i);
  }

  return 0;
}