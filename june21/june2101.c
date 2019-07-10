
#include <stdio.h>
#include <stdlib.h>  /* For malloc, EXIT_FAILURE, EXIT_SUCCESS */

/* Notice tag and typedef identifier can be the same */
typedef struct Student {
   char *name;
   int age;
} Student;

int main(){
   Student *student;
   int length;
   
   /* Allocating space for a Student structure */
   student = malloc(sizeof(Student));
   if (student == NULL) { exit(EXIT_FAILURE); }
 
   /* Allocating space for name */ 
   printf("Enter number of characters in your name: ");
   scanf("%d", &length);
   student->name = malloc(length + 1);
   
   /* Reading name and age */
   printf("Enter your name: ");
   scanf("%s", student->name);
   printf("Enter your age: ");
   scanf("%d", &student->age);

   /* Feedback */
   printf("Your name is %s and your age is %d\n", student->name, student->age);

   /* Freeing memory */
   /* We must free name first */
   free(student->name);
   free(student);


   return EXIT_SUCCESS;
}