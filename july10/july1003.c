/***********************************************/
/* The program reads two integer values. The   */
/* parent will call even_odd on the first      */
/* value and the child on the second. Notice   */
/* we need the exit(0) in the process_values() */
/* function, otherwise you will be printing    */
/* "Done in Main" twice. In this example we    */
/* do not want the child to return to main().  */
/***********************************************/
#include <sysexits.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void process_values(int x, int y);

void even_odd(int a) {
   if (a % 2 == 0) {
      printf("%d is even\n", a);
   } else {
      printf("%d is odd\n", a);
   }
}

int main() {
   int m, k;

   printf("Enter two integer values: ");
   scanf("%d%d", &m, &k);

   process_values(m, k);

   printf("Done in Main\n");

   return 0;
}

void process_values(int x, int y) {
   pid_t pid;

   if ((pid = fork()) < 0) {
      err(EX_OSERR, "fork error");
   }

   if (pid != 0) { /* parent code */
      even_odd(x);
   } else { /* child code */
      even_odd(y);
      exit(0);  /* WHY WE NEED IT? Remove it and run */
   }
}