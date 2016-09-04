#import <stdio.h>
#import <math.h>
#import <cs50.h>

/*
// version with subtraction
int main() {
  
  float change;
  
  do {
    printf("Send me a float ");
    change = GetFloat();
  } while (change < 0);
  
  int cents = round(change*100);
  
  int coins = 0;
  
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
  }
  
  printf("Cents: %d\t Coins: %d\n", cents, coins);
  
}
*/

int main() {
  
  float change;
  
  do {
    printf("Your change in dollars: ");
    change = GetFloat();
  } while (change < 0);
  
  int balance = round(change*100);
  int coin[] = {25, 10, 5, 1};
  int coin_count = 0;
  
  for (int i = 0; balance > 0; i++) {
    coin_count += balance / coin[i];
    balance %= coin[i];
  }
  
  printf("Minimum coins for $%.2f change is %i.\n", change, coin_count);
  
}