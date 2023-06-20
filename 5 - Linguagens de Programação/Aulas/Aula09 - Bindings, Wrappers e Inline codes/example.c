#include "example.h"

unsigned int fibo(unsigned short int n) {
    if (n < 2)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}