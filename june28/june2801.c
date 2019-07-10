#include <stdio.h>

int main() {
   unsigned int k = 0, limit = 32;
    
   for (k = 0; k <= limit; k++) {
      printf("%d --> %08x\n", k, k);
   }

   return 0;
}