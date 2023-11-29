// reflows text so text fits within specified width.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char message[] = 
  "Hi, Tim,\n"
  "\n"
  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod\n"
  "tempor incididunt ut labore et dolore magna aliqua.  Ut enim ad minim veniam,\n"
  "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo\n"
  "consequat.  Duis aute irure dolor in reprehenderit in voluptate velit esse\n"
  "cillum dolore eu fugiat nulla pariatur.  Excepteur sint occaecat cupidatat\n"
  "non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";


char *
reflow_text (char *buf, int new_width)
{
  
  // track line width
  int line_width = 0;

  // current index
  int index = 0;

// loop through buf
  while (index < strlen(buf)) {

      // extend short lines
      if (buf[index] == '\n') {
        if ((index - line_width) < new_width) {
          buf[index] = ' ';
        } 
      }

      // break long lines
      if((index - line_width) > new_width) {
        int reverse_index = index;

        // don't break mid-word, unless new_width is smaller than word width
        while (buf[reverse_index] != ' ') {
          reverse_index--;
          if (buf[reverse_index] == '\n' || reverse_index == 0) {
            reverse_index = index;
            break;
          }
        }

        buf[reverse_index] = '\n';
        index = reverse_index+1;
        line_width = index;
      } else {
        index++;
    }
  }
  return buf;
}

int
main (int ac, char **av)
{
  char *reflowed;

  reflowed = reflow_text (message, 32);
  printf ("%s", reflowed);
}