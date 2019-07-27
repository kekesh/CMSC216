#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include <string.h>

/* same as 0666, but a bit more symbolic (we could use #define DEF_MODE 0666 )*/
#define DEF_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main() {
   int fd;

   fd = open("message.txt", O_WRONLY|O_TRUNC|O_CREAT, DEF_MODE);
   if (fd == -1) {
      err(EX_OSERR, "can't open message.txt");
   } else {
      char msg[] = "Hi there!";
      write(fd, msg, strlen(msg));
   } 

   if (close(fd) == -1) {
      err(EX_OSERR, "closing file failed\n");
   } else {
      printf("File message.txt has been created\n");
   }
   
   return 0;
}