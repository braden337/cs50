#include <stdio.h>
#include <cs50.h>

int main(void) {
  int showerMinutes;
  printf("minutes: ");
  showerMinutes = get_int();
  printf("bottles: %d\n", showerMinutes * 192 / 16);
}
