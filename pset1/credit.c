#import <stdio.h>
#import <math.h>
#import <cs50.h>

int main(void) {

  long long card = -1;
  int odd, even, type, i;
  odd = even = type = 0;
  i = 1;
  
  while (card < 0) {
    printf("Card: ");
    card = get_long_long();
  }
  
  while (card > 0) {
    int digit = card % 10;
    
    if (card < 100 && card > 9) {
      type = card;
    }
    
    if (i % 2 == 1) {
      odd += digit;
    }
    else {
      digit *= 2;
      even += digit / 10 + digit % 10;
    }
    
    card /= 10;
    i++;
  }
  
  int checksum = even + odd;
  
  if (checksum % 10 == 0) {
    if (type / 10 == 4) {
      printf("VISA\n");
    }
    else if (type == 34 || type == 37) {
      printf("AMEX\n");
    }
    else if (type > 50 && type < 56) {
      printf("MASTERCARD\n");
    }
  }
  else {
    printf("INVALID\n");
  }
  
  return 0;
}