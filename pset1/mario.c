#include <stdio.h>
#include <cs50.h>

void printThings(int amount, char character);

int main() {
  
  int height;
  int spaces;
  
  do {
    printf("Height: ");
    height = GetInt();
  } while (height > 23 || height < 0);

  for (int i = 1; i <= height; i++) {
    spaces = height-i;
    printThings(spaces, ' ');
    printThings(height-spaces, '#');
    printThings(2, ' ');
    printThings(height-spaces, '#');
    printf("\n");
    
  }

  // for (int i = 1; i <= height; i++) {
  //   for (int j = 0; j < height; j++) {
  //     if (j < height - i) {
  //       printf(" ");
  //     } else {
  //       printf("#");
  //     }
  //   }
  //   printf("#\n");
  // }
  
  
  
  
  
}


void printThings(int amount, char character) {
  for(int j = 0; j < amount; j++) {
    printf("%c", character);
  }
}
