#include <stdio.h>

int b;

int func(int a) {
    b = 20;
    return a * a;
}

int main() {
    int a = 2;
    b = 10;
    int c = 2;
    printf("%d\n", (b + func(a)) / (func(a) - c));
    int temp = func(a);
    printf("%d\n", (temp + b) / (temp - c));
}