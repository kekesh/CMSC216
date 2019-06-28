#include <stdio.h>
#include <string.h>

#define MAX_LEN 80
#define ROSTER_MAX_LEN 2

typedef struct student {
   int id;
   char name[MAX_LEN + 1];
} Student;

void print_roster(Student *roster, int length) {
   int i;

   for (i = 0; i < length; i++) {
      printf("%d - %s\n", roster[i].id, roster[i].name);
   }
}

int main() {
   Student roster[ROSTER_MAX_LEN] = {{10, "Kelly"}, 
                        {20, "John"}};
   Student copy[ROSTER_MAX_LEN];
   char name[MAX_LEN + 1];

   print_roster(roster, ROSTER_MAX_LEN);
   memcpy(copy, roster, ROSTER_MAX_LEN * sizeof(Student)); 
   print_roster(copy, ROSTER_MAX_LEN);
   
   /* memset */
   memset(name, 'a', MAX_LEN / 2);
   name[MAX_LEN / 2] = '\0';
   printf("%s\n", name);
   
   return 0;
}