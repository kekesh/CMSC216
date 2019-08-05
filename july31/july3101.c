#include <stdio.h>
#include <stdlib.h>

unsigned long fib(unsigned int n) {
    static unsigned int table[100] = {0};
    if (n == 0 || n == 1) {
        return 1;
    }
    if (table[n]) {
        return table[n];
    }
    return table[n] = fib(n - 1) + fib(n - 2);
}