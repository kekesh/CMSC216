#include <stdio.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>     /* Required by fork() */  
#include <sys/types.h>  /* Required by pid_t */

int main() {
   pid_t result;

   printf("Hello\n");

   result = fork();
   if (result < 0) {
      err(EX_OSERR, "fork error");
   }

   printf("End: Value returned by fork: %d\n", result);

   return 0;
}