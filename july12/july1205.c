#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
   pid_t child_pid;

   if ((child_pid = fork()) < 0) {
      err(EX_OSERR, "fork error");
   }
   if (child_pid != 0) { /* parent code */
       int status;

       wait(&status);  /* reaping and waiting for child */
       if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
          printf("Child has finished successfully\n");
       }
   } else { /* child code */
      printf("PID %d (child) will now execute execlp\n", getpid());

      /* I want to become the evens program */
      execlp("./evens", "evens", NULL); 

      printf("Would this be ever printed?\n");
      err(EX_OSERR, "exec error");  /* why no if statement? */
   }

   return 0;
}