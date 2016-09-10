#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int k;

char caesar(char l, int upper);

int main(int argc, string argv[])
{

  if (argc != 2)
  {
    printf("Usage: ./caesar k\n");
    return 1;
  }

  k = atoi(argv[1]);
  char letter;

  printf(" plaintext: ");
  string plain = get_string();

  printf("ciphertext: ");
  
  for (int i = 0, len = strlen(plain); i < len; i++)
  {
    letter = plain[i];

    if (isalpha(letter))
      printf("%c", caesar(letter, isupper(letter)));
    else
      printf("%c", plain[i]);
  }

  printf("\n");

  return 0;
}

char caesar(char letter, int upper)
{
  int offset = upper ? 65 : 97;
  int cipher = (letter - offset + k) % 26;
  return cipher + offset;
}