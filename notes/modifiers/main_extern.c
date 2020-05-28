#include <stdio.h> 

int main(void) {

  size_t i;
  extern char week_days[5][10];

  for(i = 0; i < 5; i++) {
    puts(week_days[i]);
  }
  return 0;

}