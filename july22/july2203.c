#include <stdio.h>
#include <stdlib.h>

#define LOOPS 10000000

static int count = 0;

void *counter(void *args) {
   int i;

   for (i = 0; i < LOOPS; i++) {
      count++;
   }
   printf("Executed %d times\n", i);

   return NULL;
}

int main() {
   pthread_t tids[2];

   pthread_create(&tids[0], NULL, counter, NULL);
   pthread_create(&tids[1], NULL, counter, NULL);
   pthread_join(tids[0], NULL);
   pthread_join(tids[1], NULL);
   printf("Count: %d\n", count);

   return 0;
}