#include <stdio.h>

// Coded by rtpardavila@gmail.com; feel free to contact me at your discretion :)

// Constants
#define EX_OK         0
#define NO_MULTIPLES  10

int main (void) {

  // 1) user inputs integer number
  int n = 0;
  scanf("%d", &n);

  // 2) Loop, calc and print
  for (int i = 1; i <= NO_MULTIPLES; i++) {
    printf("%d x %d = %d\n", n, i, (n*i));
  }

  return EX_OK;

}
