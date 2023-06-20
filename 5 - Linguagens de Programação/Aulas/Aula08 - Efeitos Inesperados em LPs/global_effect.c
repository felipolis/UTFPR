#include <stdio.h>

int a = 5;

int func() {
    a = 15;
    return 10;
}

int main() {
    a = a + func();
    printf("%d\n", a);
}