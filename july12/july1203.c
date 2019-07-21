/*
 * 1. Do not confuse the exit status (value returned from
 *    the program using exit or return from main) with
 *    the value that is initialized by wait (e.g., wait(&status)).
 *    The status integer has the exit status and additional
 *    information.  We use the macros WIFEXITED(status), 
 *    WEXITSTATUS(status) and WTERMSIG(status) to retrieve that information.
 * 
 * 2. WIFEXITED(status) - true if the program terminated
 *    normally via exit or return from main.  Two examples
 *    of when a program does not terminate normally: when
 *    a segmentation fault takes place or if the program is
 *    terminated via a signal (e.g., kill <process_id>).   
 *
 * 3. Remember that in Unix a program indicates it completed
 *    the expected task by returning 0 (e.g., exit(0)).
 *
 * 4. You can list signals by using kill -l
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sysexits.h> 
#include <err.h> 
#include <unistd.h>    /* Required by fork(), getpid, getppid */
#include <sys/types.h> /* Required by pid_t */

int main() {
   pid_t process_id;

   if ((process_id = fork()) < 0) {
      err(EX_OSERR, "fork error");
   }

   if (process_id != 0) { /* Parent code */
      int status;  

      wait(&status);
      if (WIFEXITED(status)) {
         printf("Child finished normally (via exit or return in main)\n");
     if (WEXITSTATUS(status) == 0) {
            printf("Child completed the task successfully\n");    
     } else {
            printf("Child did NOT complete the task successfully\n");    
     }
      } else {
         printf("Child did NOT finish normally (via exit or return in main); signal must have occured\n");
         printf("REPORT:\n");
     printf("WIFEXITED(status): %d\n", WIFEXITED(status));
     printf("WEXITSTATUS(status): %d\n", WEXITSTATUS(status));
     printf("WTERMSIG(status) - (signal caused child to terminate): %d\n", WTERMSIG(status));
      }

      exit(0); /* Parent exit */

   } else {  /* Child code */
      int value;

      printf("Enter case (1, 2, 3, 4): ");
      printf("Or instead of entering a number kill the child process (kill <process_id>) (see output)\n");
      scanf("%d", &value);
      if (value == 1) {
         char *p = NULL;
         *p = 20;
         exit(100);
      } else if (value == 2){
         int x;

         printf("Enter positive integer: ");
         scanf("%d", &x);
         printf("Squared value is %d\n", x * x);
         exit(0);
      } else if (value == 3) {
         int x = 0;
     printf("%d\n", 1 / x);
         exit(30);
      } else {
         int x;

         printf("Enter positive integer > 0: ");
         scanf("%d", &x);
         if (x > 0) {
            printf("The cube of %d is %d\n", x, x * x * x);
            exit(0);
         }
         exit(40);
      }
   }
}