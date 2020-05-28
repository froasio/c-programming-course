#include <stdio.h>      
#include <stdlib.h>  

/*

  atoi(), atol(), atof()

  int atoi (const char * str);
  
*/

int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);

  i = atoi (buffer);

  printf ("The value entered is %d. Its double is %d.\n", i, i*2);
  
  return 0;
}