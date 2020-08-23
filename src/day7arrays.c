#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lib/excodes.h"

#define N_MIN 1
#define N_MAX 1000
#define A_MIN 1
#define A_MAX 10000
#define AI_CH_MAX 5
#define N_ZERO (int)'0'
#define N_NINE (int)'9'
#define DEBUG 0

int ch2int(char);
int chbuff__2uint(char *, int);

int main (void) {

  char ch = '\0';
  int num_i = 0;
  char ai_buff[AI_CH_MAX];
  int ai_buff_i = 0;
  int n = 0, ai_aux = 0;
  int* array;

  // TODO :: Read a string better and work with elements of the string library
  scanf("%d", &n); getchar();
  if ( (n < N_MIN) || (n > N_MAX)) {
    printf("Wrong 'n' parameter value = %d, required range [%d, %d]", n, N_MIN, N_MAX);
    return EX_OK;
  }

  if ( ( array = (int*)malloc(n*sizeof(int)) ) < 0 ) {
    printf("Cannot allocate required memory, %ld bytes", n*sizeof(int));
    return EX_MEMORY;
  };

  while (ch = getchar()) {

    if (DEBUG) printf("ch = %c\n", ch);

    if ((ch == ' ') || (ch == '\n') || (ch == EOF)) {

      ai_aux = chbuff__2uint(ai_buff, ai_buff_i);

      if (ai_aux > A_MAX) {
        printf("Number is too long for the array, max = %d\n", A_MAX);
        return EX_NUMTOOLONG;
      }

      array[num_i++] = ai_aux;
      ai_buff_i = 0;
      memset(ai_buff, 0x00, AI_CH_MAX);

      // The current algorithm will read all the numbers, but just process them in accordance to the max spec
      // numbers given by parameter 'n'
      if (num_i == n) { break; }

      if ((ch == '\n') || (ch == EOF)) { if (DEBUG) printf("%c (\\n or EOF) break", ch); break; }
      continue;

    }

    if ((ch < N_ZERO) || (ch > N_NINE)) { printf("Only numerical characters allowed.\n");  break; }   // no negatives

    if (ai_buff_i > AI_CH_MAX) {
      printf("Number is too long for the array, max characters = %d", AI_CH_MAX);
      return EX_NUMTOOLONG;
    }

    ai_buff[ai_buff_i++] = ch;
    if (DEBUG) printf("ai_buff = %s\n", ai_buff);

  }

  for (int i = 1; i <= num_i; i++) printf("%d ", array[num_i - i]);

}

int char2int(char ch) { return (int)ch - N_ZERO; }

int chbuff__2uint(char *buff, int len) {
  int result = 0;
  for (int i = 1; i <= len; i++) result += char2int(buff[i - 1])*(int)pow(10., 1.*(len - i));
  return result;
}
