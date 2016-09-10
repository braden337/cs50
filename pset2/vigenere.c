#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string key;
int k;
int keylen;

char vigenere(char l, int upper);

int main(int argc, string argv[])
{

  if (argc != 2)
  {
    printf("Usage: ./vigenere key\n");
    return 1;
  }

  key = argv[1];
  k = 0;
  keylen = strlen(key);
  char letter;

  printf(" plaintext: ");
  string plain = get_string();

  printf("ciphertext: ");
  
  for (int i = 0, len = strlen(plain); i < len; i++)
  {
    letter = plain[i];

    if (isalpha(letter))
      printf("%c", vigenere(letter, isupper(letter)));
    else
      printf("%c", plain[i]);
  }

  printf("\n");

  return 0;
}

char vigenere(char letter, int upper)
{
  int offset = upper ? 65 : 97;
  int shift = toupper(key[k]) - 65;
  int cipher = (letter - offset + shift) % 26;
  k = (k == keylen - 1) ? 0 : k + 1;
  return cipher + offset;
}