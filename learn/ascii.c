#include <stdio.h>
// #include <cs50.h>
// #include <string.h>

int main(void)
{
  printf("Printable letters\n");
  for (int i = 32; i < 127; ++i)
  {
    printf("%c: %i\n", (char) i, i);
  }

  return 0;
}