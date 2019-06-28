#include <stdio.h>
int main() {
    int *p; 
    int x;
    p = &x; /* This is correct! */
    *p = 200;
    printf("The value is %d\n", *p);
    return 0;
}
