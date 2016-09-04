#import <stdio.h>
#import <math.h>
#import <cs50.h>

int main() {
  
  float change = -1.0;
  
  while (change < 0) {
    printf("Your change in dollars: ");
    change = get_float();
  }
  
  int balance = round(change*100);
  int coin[] = {25, 10, 5, 1};
  int coin_count = 0;
  
  for (int i = 0; balance > 0; i++) {
    coin_count += balance / coin[i];
    balance %= coin[i];
  }
  
  // printf("Minimum coins for $%.2f change is %i.\n", change, coin_count);
  printf("%i\n", coin_count);
  
}