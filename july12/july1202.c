#include <sys/wait.h>
#include <sysexits.h> 
#include <err.h>
#include <unistd.h> 
#include <sys/types.h> 

int main() {
   pid_t pid, returned_value;
   

   if ((pid = fork()) < 0) {
      err(EX_OSERR, "fork error");
   }
   if (pid) { /* parent code, pid != 0 */
      printf("Parent waiting for child\n");
      returned_value = wait(NULL);  /* nothing happens until child exits; reaps the child */
      printf("Value returned by wait: %d\n", returned_value);
      printf("Parent pid = %d; my child had pid = %d\n", getpid(), pid);
   } else { /* child code */
      sleep(4); /* simulating child's processing, waiting 4 seconds */
      printf("Child pid = %d; my parent has pid = %d\n", getpid(), getppid());
   }
   
   return 0;
}