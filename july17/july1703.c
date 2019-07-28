#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LEN 80

void print_powers(int limit) {
   int i = 0;

   for (i = 0; i <= limit; i++) {
      printf("%d\n", i * i);
   }
}

int main() {
   char filename[MAX_LEN + 1] = "results.txt";
   int fd;

   if ((fd = open(filename, O_CREAT | O_WRONLY, 0666)) < 0) {
      err(EX_OSERR, "File opening failed\n");
   }
   printf("Results can be found at %s\n", filename);
   dup2(fd, STDOUT_FILENO);     /* redirecting */
   close(fd);                   /* releasing resource */

   print_powers(10);

   return 0;
}