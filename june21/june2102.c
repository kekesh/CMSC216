int *p, *q; /* Declare two integer pointers */
p = malloc(sizeof(int)); /* Dynamically allocate memory */
if (p != NULL) { /* Make sure allocation succeeded. */
    *p = 99; /* Dereference p; set its entity to 99. */
    q = p; /* q points to the same memory address as p */
    free(p) /* BOTH p and q are dangling pointers now */
    *q = 42; /* This is WRONG. */
}