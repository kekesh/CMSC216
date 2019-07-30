#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
 
/*
 * Execute "time sleeper"
 */
int main() {
   long x = 900000000;

   while(x-- > 0);
   printf("About to sleep for 5 seconds\n");
   sleep(5);
   printf("Done\n");

   return 0;
}