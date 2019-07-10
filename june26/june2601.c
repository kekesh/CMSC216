void print_decimal(unsigned int i) {
   printf("%u\n", i);
}

void print_hex(unsigned int i) {
   printf("%x\n", i);
}

void print_octal(unsigned int i) {
   printf("%o\n", i);
}

int main() {
   /* The following is the declaration of */
   /* fp as a function pointer variable   */
   void (*fp)(unsigned int); 

   /* Below both & and * are optional */
   /* due to the use of the function */
   /* call operator */

   fp = print_hex;
   fp(16);  /* prints "10" */
   fp = &print_octal;
   fp(16);  /* prints "20" */
   fp = print_decimal;
   (*fp)(16);  /* prints "16" */

   return 0;
}