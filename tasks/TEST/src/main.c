#include <stdio.h>
/**
 * Spoj problem TEST
 * prints all numbers from input until 42 is found
 */
int main() {
  int number;
  for (;;) {
    int e = scanf("%d", &number);
    if (e == EOF) return 1;
    if (number == 42)
      break;
    printf("%d\n", number);
  }
  return 0;
}
