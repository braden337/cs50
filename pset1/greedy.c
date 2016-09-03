#import <stdio.h>
#import <math.h>
#import <cs50.h>


int main() {
  
  float change;
  
  do {
    printf("Send me a float ");
    change = GetFloat();
  } while (change < 0);
  
  int cents = round(change*100);
  
  int coins = 0;
  
  // printf("Cents: %d\t Coins: %d\n", cents, coins);
  
  while (cents > 0) {
    if (cents >= 25) {
      cents -= 25;
      coins++;
    }
    else if (cents >= 10) {
    cents -= 10;
    coins++;
    }
    else if (cents >= 5) {
      cents -= 5;
      coins++;
    }
    else if (cents >= 1) {
      cents -= 1;
      coins++;
    }
    
    // printf("Cents: %d\t Coins: %d\n", cents, coins);
    
  }
  
  printf("%d\n", coins);
  
}
