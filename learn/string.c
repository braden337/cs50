#include <stdio.h>
#include <cs50.h>
// #include <string.h>

int len(string str);

int main(void)
{
  // Get a line of text and calculate the length
  string str = get_string();
  int l = len(str);

  // Print one character per line
  for (int i = 0; i < l; i++)
    printf("%c\n", str[i]);
  
  return 0;
}

// My own version of strlen()
int len(string str)
{
  int i = 0;
  while (1)
  {
    if (str[i] == '\0')
      return i;
    else
      i++;
  }
}