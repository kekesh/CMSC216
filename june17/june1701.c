#include <stdlib.h> 

#define MAX_LEN 80

int main() {
   FILE *input; /* does not need to be named input */
   char line[MAX_LEN + 1], filename[MAX_LEN + 1];   

   printf("Input file name (e.g., data.txt): ");
   scanf("%s", filename);
   if ((input = fopen(filename, "r")) == NULL) {
      perror("error opening file");
      exit(EXIT_FAILURE);
   } else {
      while (fgets(line, MAX_LEN + 1, input) != NULL) {
         printf("%s", line);
      } 
      fclose(input);
      exit(EXIT_SUCCESS);
   }
}