#include <stdio.h>
#include <cs50.h>

int gcd(int a, int b);

int main(void) {

  int a, b;

  printf("A: ");
  a = get_int();

  printf("B: ");
  b = get_int();

  // printf("\n%-10c %-10c\n", 'A', 'B');
  printf("\nGCD is %i\n", gcd(a,b));

}

int gcd(int a, int b) {
  // printf("%-10i %-10i\n", a, b);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}