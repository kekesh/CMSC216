#include <stdio.h>

int main() {
   unsigned int value = 0x01234567;
   int i;

   char *value_ptr = (char *)&value;
   if (*value_ptr == 0x67) {
      printf("It is little endian\n");
   } else {
      printf("It is Big endian\n");
   }
   printf("Bytes: ");
   for (i = 1; i <= 4; i++, value_ptr++) {
      printf("%02x", *value_ptr);
   }

   return 0;
}