#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *get_square(void *args);

int main() {
   pthread_t tid;
   void *result_ptr = NULL;
   int argument;

   printf("Input value to compute square: ");
   scanf("%d", &argument);

   pthread_create(&tid, NULL, get_square, &argument);
   pthread_join(tid, &result_ptr); /* notice use of & */
   printf("Square of %d is %d \n", argument, *(int *)result_ptr);

   free(result_ptr);

   return 0;
}

void *get_square(void *args) {
   int argument = *(int *)args;
   int *answer_ptr = malloc(sizeof(int));

   *answer_ptr = argument * argument;  

   return answer_ptr;
}