// Coded by rtpardavila@gmail.com; feel free to contact me :)

#include <stdio.h>
#include <stdlib.h>

#include "lib/excodes.h"
#include "lib/strbuffer.h"

// Flag that marks whether debug symbols should be output or not
#define DEBUG         0

int main (void) {

  u_int16_t T = 0;
  t_sbuffer *buffer = NULL;

  // 1) first we get the number of test strings from the user
  scanf("%hd", &T); getchar(); // getchar is necessary to read the last end line character
  if ( ( T < T_MIN) || ( T > T_MAX ) ) {
    printf("The value for 'T' must be [%d, %d]\n", T_MIN, T_MAX);
    return EX_WRONGARGS;
  }

  // 2) Create buffer for holding up all strings
  if ( t_sbuffer__init(&buffer, T) == EX_MEMORY ) {
    printf("Cannot allocate memory, exiting...\n"); return EX_MEMORY;
  }

  // 3) Get input strings from user
  for ( int i = 0; i < T; i++ ) {

    if ( t_sbuffer__readnext(buffer) == EX_STRTOOLONG ) {
      printf("The string is too long, max length = %d\n", S_LEN_MAX);
      return EX_STRTOOLONG;
    }

    if ( DEBUG ) t_sbuffer__print(buffer);

  }

  // 4) Process the data
  t_sbuffer__process(buffer);

  // 5) Free memory before leaving
  t_sbuffer__free(buffer);

  return EX_OK;

}
