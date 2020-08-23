// Coded by rtpardavila@gmail.com; feel free to contact me :)

/* BEGIN strbuffer.h */
#ifndef H_STRBUFFER
#define H_STRBUFFER

#include <stdlib.h>

// Buffer structure, helps making the code more robust
// Since max size of each string is 10000, we use uint16 for the length and next types.
typedef struct {
  u_int16_t length;
  u_int16_t next;
  char *buffer;
} t_sbuffer;

extern t_sbuffer __t_sbuffer;

#define SIZE_T_SBUFFER sizeof(t_sbuffer)

#define T_MIN         1
#define T_MAX         10
#define S_LEN_MIN     2
#define S_LEN_MAX     10000
// The maximum length of the string needs to account for the extra '\0' line terminator
#define S_BUFF_LEN    S_LEN_MAX + 1

int   t_sbuffer__init     (t_sbuffer**, int);
int   t_sbuffer__free     (t_sbuffer*);
int   t_sbuffer__readnext (t_sbuffer* );
void  t_sbuffer__print    (t_sbuffer*);
int   t_sbuffer__process  (t_sbuffer*);

#endif
/* END strbuffer.h */
