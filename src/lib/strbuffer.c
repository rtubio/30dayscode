// Coded by rtpardavila@gmail.com; feel free to contact me :)

#include <stdio.h>
#include <string.h>

#include "excodes.h"
#include "strbuffer.h"

/*
    Init method for the buffer structure.
    This method allocates the memory necessary for the structure and for the string buffer that it holds.

    t_sbuffer **buffer  ~ pointer reference to the external buffer
    uint16_t length     ~ number of strings to be held int the string buffer
*/
int t_sbuffer__init (t_sbuffer** buffer, int length) {

  if ( ( (*buffer) = (t_sbuffer*)malloc(SIZE_T_SBUFFER) ) == NULL ) return EX_MEMORY;
  (*buffer)->length = length;
  (*buffer)->next = 0;
  if ( ((*buffer)->buffer = (char *)malloc(length*S_BUFF_LEN*sizeof(char)) ) == NULL) return EX_MEMORY;

  return EX_OK;

}

/*
    Free method for the buffer structure.
    This method frees the allocated memory, both for the structure and for the string buffer within the structure.

    t_sbuffer **buffer  ~ pointer reference to the external buffer
*/
int t_sbuffer__free (t_sbuffer* buffer) {
  free(buffer->buffer);
  free(buffer);
  return EX_OK;
}

/**
    This function process the string buffer and generates the requierd output.

    t_sbuffer* buffer ~ structure with the buffer itself
*/
int t_sbuffer__process (t_sbuffer* buffer) {

  char ch = '\n';
  u_int16_t even_i = 0, odd_i = 0, ch_i = 0;
  char* even = (char*)malloc(S_BUFF_LEN);
  char* odd = (char*)malloc(S_BUFF_LEN);

  for ( int i = 0; i < buffer->next; i++ ) {

    memset(even, 0x00, S_BUFF_LEN);
    memset(odd, 0x00, S_BUFF_LEN);

    while (
      ( buffer->buffer[i*S_BUFF_LEN + ch_i] != '\n' ) &&
      ( buffer->buffer[i*S_BUFF_LEN + ch_i] != EOF )
    ) {

      ch = buffer->buffer[i*S_BUFF_LEN + ch_i++];
      if ( ch_i % 2 ) odd[odd_i++] = ch;
      else even[even_i++] = ch;

    }

    printf("%s %s\n", odd, even);
    ch_i = 0; even_i = 0; odd_i = 0;

  }

  return EX_OK;

}


/**
    Function to read a new string within the buffer.

    t_sbuffer* buffer ~ structure with the buffer itself
*/
int t_sbuffer__readnext (t_sbuffer* buffer) {

  char ch = 'a';
  u_int16_t read_ch = 0;

  if (buffer->next == buffer->length) return EX_BUFFERFULL;

  // TODO :: need to check the case for which the length is too long
  while ( ( ch != '\n' ) && ( ch != EOF ) ) {
      ch = getchar();
      buffer->buffer[buffer->next*S_BUFF_LEN + read_ch] = ch;
      if (read_ch++ > S_LEN_MAX) return EX_STRTOOLONG;
  }

  buffer->next++;
  return EX_OK;

}

/**
    Auxiliary function that helps visualizing the contents of the string buffer.
    The string buffer is an array of strings where the input strings from the user are kept.

    t_sbuffer* buffer ~ structure with the buffer itself
*/
void t_sbuffer__print (t_sbuffer* buffer) {

  printf("buffer.length = %d\n", buffer->length);
  if (buffer->next == 0) { printf("buffer.buffer = [EMPTY]\n"); return; }

  for (int i = 0; i < buffer->next; i++) {
    printf("@%d, pos = %d, string = %s", i, (i*S_BUFF_LEN), (char *)&buffer->buffer[i*S_BUFF_LEN]);
  }

}
