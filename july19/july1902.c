#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>

#define MAX_STR_LEN 80

int main() {
   int pipe_fd[2];
   pid_t child_pid;
   char value[MAX_STR_LEN + 1];

   printf("Enter number: ");
   fgets(value, MAX_STR_LEN + 1, stdin);

   if (pipe(pipe_fd) < 0) { err(EX_OSERR, "pipe error"); }
   if ((child_pid = fork()) < 0) { err(EX_OSERR, "fork error"); }

   if (child_pid) { /* parent code */
      close(pipe_fd[0]);   /* closing read end */
      write(pipe_fd[1], value, MAX_STR_LEN + 1); /* placing data in pipe */
      close(pipe_fd[1]);   /* closing write end */
      wait(NULL);  /* reaping */
   } else { /* child code */
      close(pipe_fd[1]);   /* closing write end */

      if (dup2(pipe_fd[0], STDIN_FILENO) < 0) { err(EX_OSERR, "dup2 error"); }
      close(pipe_fd[0]);
      execlp("./table", "table", NULL);
      err(EX_OSERR, "exec error");
   }

   return 0;
}