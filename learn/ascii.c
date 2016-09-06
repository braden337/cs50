#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>
// #include <time.h>
// #include <stdlib.h>

int main(void)
{
  // srand(time(NULL));

 // string s = "12345678";

  // int letters[95]; 

  // for (int i = 32, x = 0; i < 127; i++)
  // {
  //   letters[x] = i;
  //   x++;
  // }

  // int x = 0;
  // while (x < 100)
  // {
    // printf("%i\n", rand() % 94);
    // x++;
  // }
  string password = "abcdefghijklmnopqrstuvwxyztuytuytuytuytuygtyutuytfuyetgruytweruytweurytweuryweueuy";
  string hashes[] = {"HALRCq0IBXEPM", "50zPJlUFIYY0o", "50MxVjGD7EfY6", "50z2Htq2DN2qs", "50CMVwEqJXRUY", "50TGdEyijNDNY", "50QykIulIPuKI", "50q.zrL5e0Sak", "50Bpa7n/23iug", "HAYRs6vZAb4wo"};
  string hash;
  char salt[3];
  do {
    password = get_string();
    for (int i = 0; i < 10; i++)
    {
      hash = hashes[i];
      salt[0] = hash[0];
      salt[1] = hash[1];
      if (strcmp(hash, crypt(password, salt)) == 0)
      {
        printf("%s %s\n", password, hash);
        hashes[i] = "";
      }
    }

  }
  while(strcmp(password, "zyloprim"));

  // string pass;
  // // char fullSalt[50] = "$1$";

  // printf("Word: ");
  // pass = get_string();
  
  // printf("Salt: ");
  // string salt = get_string();
  // // strcat(fullSalt, salt);
  // // strcat(fullSalt, "$");
  // printf("Hash: %s, %s, %s\n", crypt(word, salt), word, salt);

  return 0;
}
