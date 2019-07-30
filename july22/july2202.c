#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define THREAD_CT 8

void *print_stuff(void *ptr) {
   int k, id = *(int *) ptr;

   for (k = 0; k <= 4; k++) {
      printf("Thread %d, ", id);
      fflush(stdout);
      printf("loop %d\n", k);
      fflush(stdout);
      sleep(rand() % 2);  /* sleep 0 or 1 seconds */
   }
   printf("Thread %d exiting\n", id);

   return NULL;
}

int main() {
   pthread_t tids[THREAD_CT + 1];
   int i, ids[THREAD_CT + 1];

   for (i = 1; i <= THREAD_CT; i++) {
      ids[i] = i;
      pthread_create(&tids[i], NULL, print_stuff, &ids[i]);
      printf("Thread 0 created thread %d\n", i);
   }

   for (i = 1; i <= THREAD_CT; i++) {
      pthread_join(tids[i], NULL);
      printf("Thread 0 reaped thread %d\n", i);
   }

   return 0;
}