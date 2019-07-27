#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>

#define LENGTH 9

int main() {
   int fd;
   char buf[LENGTH]; 
   size_t bytes_read;

   fd = open("message.txt", O_RDONLY);
   if (fd == -1) {
      err(EX_OSERR,"Cannot open file");
   } else {
      int i;
      bytes_read = read(fd, buf, LENGTH);
      if (bytes_read != LENGTH) {
         err(EX_OSERR, "Problem reading data");
      }
      for (i = 0; i < LENGTH; i++) {
         printf("%c", buf[i]);
      }
   }

   if (close(fd) == -1) {
      err(EX_OSERR, "Closing file failed");
   } 

   return 0;
}