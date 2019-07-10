#include <stdlib.h>  /* For malloc, EXIT_FAILURE, EXIT_SUCCESS */

int main(){
   int *ip, i, array_length = 3;

   /* Allocating space for an integer */
   ip = malloc(sizeof(int)); /* notice casting is not necessary */
   if (ip == NULL) {
      exit(EXIT_FAILURE);
   }
   *ip = 104;
   printf("Value assigned is %d\n", *ip);
   free(ip); /* deallocating memory */
}