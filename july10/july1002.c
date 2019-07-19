#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>   
#include <sys/types.h>

int main() {
   pid_t result;
   int x = 20;
   char *p;

   printf("Hello\n");

   p = malloc(80);

   result = fork();
   if (result < 0) {
      err(EX_OSERR, "fork error");
   }

   /* By using the value returned by fork, we */
   /* we can tell which process is the parent */
   /* and which is the child. We can assign   */
   /* different tasks to each one.            */
   /* Notice the address values printed by    */
   /* the processes.                          */

   if (result == 0) {
      printf("I am the child (increases x) %d\n", ++x);
      printf("Value of address in child %p\n", (void *)p);
   } else { 
      printf("I am the parent (decreases x) %d\n", --x);
      printf("Value of address in parent %p\n", (void *)p);
   }

   free(p);  /* Both must free */

   printf("Done\n");

   return 0;
}