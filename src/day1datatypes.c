// The first answer works on Debian 10.5 with the following configuraiton:
//
// uname -a :: Linux sargo 4.19.0-10-amd64 #1 SMP Debian 4.19.132-1 (2020-07-24) x86_64 GNU/Linux
// gcc --version :: gcc (Debian 8.3.0-6) 8.3.0
//
// However, in the online compiler for HackerRank using the strcat function is a problem since the buffer that it is
// mandatory to use is not limited in size. Therefore, we need to create two intermediate string buffers limited in
// size to not incur in a buffer overflow.
//
/* Solution that works with the online web compilar at HackerRank...
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    // Declare second integer, double, and String variables.
    int i2 = 0;
    double d2 = 0.0;
    char s2[100] = "";
    char s3[100] = "";

    // Read and save an integer, double, and String to your variables.
    scanf("%d", &i2);
    scanf("%lf", &d2);
    getchar(); fgets(s2, sizeof(s2), stdin);

    // Print the sum of both integer variables on a new line.
    printf("%d\n", (i + i2));
    // Print the sum of the double variables on a new line.
    printf("%.1f\n", (d + d2));

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    strcat(s3, s);
    strcat(s3, s2);
    printf("%s\n", s3);

    return 0;
}
*/

#include <stdio.h>
#include <string.h>

#define EXOK            0
#define STR_BUFFSIZE    100

int     i                   = 0             ;
int     i2                  = 0             ;
double  d                   = 0.0           ;
double  d2                  = 0.0           ;
char    s [2*STR_BUFFSIZE]  = "HackerRank " ;
char    s2[STR_BUFFSIZE]    = ""            ;

int main(void) {

  printf("Input the value for i = ");
  scanf("%d", &i);
  printf("Input the value for d = ");
  scanf("%lf", &d);
  printf("Input the value for s = ");
  getchar(); fgets(s2, sizeof(s2), stdin);

  strcat(s, s2);
  printf("i+i2 = %d, d+d2 = %lf, s+s2 = %s\n", (i + i2), (d + d2), s);

  return EXOK;

}
