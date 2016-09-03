#import <stdio.h>
#import <math.h>
#import <cs50.h>

int main(void) {

  long long card;
  int last;
  int lastDoubled;
  int firstTwo = 0;
  int digit = 0;
  int sum = 0;

  printf("Card: ");
  card = GetLongLong();

  while (card > 0) {
    last = card % 10;

    if (digit % 2 == 0) {
      /* if it's an even index from the end
       just add the last digit to sum */
      sum += last;
    }
    else {
      /* else if it's an odd index from the end
       multiply it by two and add the products
       individual digits to the sum */
      lastDoubled = last * 2;

      if (lastDoubled < 10) {
        sum += lastDoubled;
      }
      else {
        /* add the digits separately
           if there is more than one */
        sum += lastDoubled % 10;
        lastDoubled /= 10;
        sum += lastDoubled;
      }
    }

    if (card > 9 && card < 100) {
      firstTwo += card % 10;
    }
    else if (card < 10) {
      firstTwo += 10 * card;
    }

    card /= 10;
    digit++;
    // printf("%d\t%lld\n", last, card);
  }

  // printf("Sum: %d\n", sum);

  if (sum % 10 != 0) {
    printf("INVALID\n");
  }
  else {
    // printf("VALID\nCard starts with \'%d\'\n", firstTwo);
    switch (firstTwo) {
      case 34:
      case 37:
        printf("AMEX\n");
        break;
      case 40:
      case 41:
      case 42:
      case 43:
      case 44:
      case 45:
      case 46:
      case 47:
      case 48:
      case 49:
        printf("VISA\n");
        break;
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
        printf("MASTERCARD\n");
    }
  }

  return 0;
}
