#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

string hash;
char salt[3];

int hashMatches(string word);

int main(int argc, string argv[])
{
  if (argc < 2)
    return 1;

  char word[5];
  hash = argv[1];
  salt[0] = hash[0];
  salt[1] = hash[1];

  // ONE LETTER WORDS

  for (int i = 65; i < 123; i++)
  {
    if (i > 90 && i < 97) continue;
    word[0] = i; word[1] = '\0';
    if (hashMatches(word)) return 0;
  }

  // TWO LETTER WORDS

  for (int i = 65; i < 123; i++)
  {
    if (i > 90 && i < 97) continue;
    for (int j = 65; j < 123; j++)
    {
      if (j > 90 && j < 97) continue;
      word[0] = i; word[1] = j;
      word[2] = '\0';
      if (hashMatches(word)) return 0;
    }
  }

  // THREE LETTER WORDS

  for (int i = 65; i < 123; i++)
  {
    if (i > 90 && i < 97) continue;
    for (int j = 65; j < 123; j++)
    {
      if (j > 90 && j < 97) continue;
      for (int k = 65; k < 123; k++)
      {
        if (k > 90 && k < 97) continue;
        word[0] = i; word[1] = j;
        word[2] = k; word[3] = '\0';
        if (hashMatches(word)) return 0;
      }
    }
  }

  // FOUR LETTER WORDS

  for (int i = 65; i < 123; i++)
  {
    if (i > 90 && i < 97) continue;
    for (int j = 65; j < 123; j++)
    {
      if (j > 90 && j < 97) continue;
      for (int k = 65; k < 123; k++)
      {
        if (k > 90 && k < 97) continue;
        for (int l = 65; l < 123; l++)
        {
          if (l > 90 && l < 97) continue;
          word[0] = i; word[1] = j;
          word[2] = k; word[3] = l;
          if (hashMatches(word)) return 0;
        }
      }
    }
  }
  return 1;
}

int hashMatches(string word)
{
  if (strcmp(crypt(word, salt), hash) == 0) 
  {
    printf("%s\n", word);
    return 1;
  }
  return 0;
}