#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct point {
   int x, y;
};

void *print_point(void *pointp);

int main() {
   pthread_t tid; /* thread id */
   struct point pt = {3, 5};

   if (pthread_create(&tid, NULL, print_point, &pt) != 0) {
      fprintf(stderr, "pthread_create failed\n");
      exit(1);
   }

   /* reaps thread blocking until thread terminates */
   printf("Waiting for child to finish\n");
   if (pthread_join(tid, NULL) != 0) {
      fprintf(stderr, "pthread_join failed\n");
   }

   printf("In main after thread finished\n");

   return 0;
}

/* code executed by the thread */
void *print_point(void *pointp) {
   struct point arg = *(struct point *)pointp;

   sleep(2); /* simulating some work */
   printf("Point: (%d, %d)\n", arg.x, arg.y);

   return NULL;
}