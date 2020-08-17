#include <stdio.h>

#define STR_SIZE  256
#define EX_OK     0

int main () {

  char inputString[STR_SIZE];
  scanf("%[^\n]", inputString);
  printf("Hello, World.\n%s\n", inputString);

  return EX_OK;

}
