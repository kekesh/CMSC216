int main() {
   /* Allocating space for array */
   int *ip = malloc(sizeof(int) * array_length);
   int array_length = 3;
   if (ip == NULL) {
      exit(EXIT_FAILURE);
   }
   for (i = 0; i < array_length; i++){
      ip[i] = i * 3;
   }
   for (i = 0; i < array_length; i++){
      printf("%d ",ip[i]); /* notice using array indexing */
   }
   printf("\n");
   free(ip); /* deallocating memory */
}