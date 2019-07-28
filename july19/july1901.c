#include <stdio.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LEN 80

void print_powers() {
   int i = 0, limit = 4;

   for(i = 0; i <= limit; i++) {
      printf("%d\n", i * i); 
   }
}

int main() {
    pid_t child_pid;
    int pipe_fd[2];
    char filename[MAX_LEN + 1];

    pipe(pipe_fd);
    child_pid = fork();

    if (child_pid) { /* parent code */
       close(pipe_fd[0]); /* closing pipe's read end */
       printf("Enter filename for results: ");
       scanf("%s", filename);  /* reading filename */
       /* sending filename */
       write(pipe_fd[1], filename, strlen(filename) + 1); 
       close(pipe_fd[1]); /* closing pipe's write end */
       wait(NULL); /* reaping */
    } else { /* child code */
       int fd;

       close(pipe_fd[1]); /* closing pipe's write end */
       read(pipe_fd[0], filename, MAX_LEN + 1); /* reading file name */
       close(pipe_fd[0]); /* closing pipe's read end */
       fd = open(filename, O_CREAT | O_WRONLY, 0666); 
       dup2(fd, STDOUT_FILENO); /* redirecting */
       close(fd); /* releasing resource */

       print_powers();
    }

    return 0;
}