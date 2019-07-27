/*
  Illustrates the file descriptors associated
  with standard input (0), standard output (1).
  Remember standard error is (2).  To run the 
  example, enter a string with a length of at
  least 5 characters.
 */
#include <stdio.h>
#include <unistd.h>

#define LENGTH 5

int main() {
   char buffer[LENGTH];

   /* Use STDIN_FILENO instead of 0 */
   read(0, buffer, LENGTH);

   /* Use STDOUT_FILENO instead of 1 */
   write(1, buffer, LENGTH);

   write(STDOUT_FILENO, "Bye\n", 4);

   return 0;
}