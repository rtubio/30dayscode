#include <stdio.h>

#define EX_OK 0

int main (void) {

  // There is no criteria set for numbers < 2; therefore we do not produce any output and we mark this matter to
  // discuss with "higher authorities".

  int n = 0;
  scanf("%d", &n);

  if ( n % 2 > 0 )                { printf("Weird\n");      return EX_OK; }
  if (( n >= 2 ) && ( n <= 5 ))   { printf("Not Weird\n");  return EX_OK; }
  if (( n >= 6 ) && ( n <= 20 ))  { printf("Weird\n");      return EX_OK; }
  if ( n > 20 )                   { printf("Not Weird\n");  return EX_OK; }

  return EX_OK;

}
