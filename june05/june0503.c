#include <stdio.h>
int* process() {
    int x = 10;
    int *p = &x;
    return p; /* This is bad - we're returning a pointer to some area that no longer exists! */
}
