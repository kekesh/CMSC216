/* 
 * Input/output redirection example
 *
 * Try 1: dup2Ex1
 *        input a string with 8 characters  
 *
 * Try 2: dup2Ex1 data.txt
 *        in data.txt you need to have 8 characters
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <err.h>
#include <sysexits.h>

#define NAME_LENGTH 8

int main(int argc, char **argv) {
   char buffer[NAME_LENGTH]; /* not including \0 */
   int fd;

   if (argc > 1) {
      if ((fd = open(argv[1], O_RDONLY)) < 0) {
         err(EX_OSERR, "File opening failed.\n");
      } 
      if (dup2(fd, STDIN_FILENO) < 0) {
         err(EX_OSERR, "dup2 error");
      }
      close(fd); /* we need it otherwise resource leak */
   }     

   read(STDIN_FILENO, buffer, NAME_LENGTH);
   write(STDOUT_FILENO, buffer, NAME_LENGTH);

   exit(0);
}