/*
 * Input/output redirection example
 *
 * Try 1: dup2Ex2
 *        input a string with 8 characters
 *
 * Try 2: dup2Ex2 data.txt
 *        in data.txt you need to have a character with 8 characters
 *
 * Try 3: dup2Ex2 data.txt output.txt
 *        output.txt will be overwritten with contents of data.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <sysexits.h>

#define NAME_LENGTH 8

#define FILE_PERMISSIONS 0666

int main(int argc, char **argv) {
   char buffer[NAME_LENGTH]; /* not including \0 */
   int fd;

   if (argc > 1) {
      /* If we have a second argument that represents the input file */
      if ((fd = open(argv[1], O_RDONLY)) < 0) {
         err(EX_OSERR, "File opening (read) failed");
      } 

      if (dup2(fd, STDIN_FILENO) < 0) {
         err(EX_OSERR, "dup2 (read) failed");
      }
       
      close(fd); /* Releasing resource */

      /* If we have a third argument that represents the output file */
      if (argc == 3) {
         if ((fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS)) < 0) {
            err(EX_OSERR, "File opening (write) failed");
         }

         if (dup2(fd, STDOUT_FILENO) < 0) {
            err(EX_OSERR, "dup2 (write) failed");
         }

         close(fd); /* Releasing resource */
      }
   }     

   /* At this point we are ready for reading/writing */

   read(STDIN_FILENO, buffer, NAME_LENGTH);
   write(STDOUT_FILENO, buffer, NAME_LENGTH);
   
   exit(0);
}