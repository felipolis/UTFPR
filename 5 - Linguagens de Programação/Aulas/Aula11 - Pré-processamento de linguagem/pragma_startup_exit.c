#include<stdio.h>

void func1();
void func2();

// outras versões exceto GCC
#pragma startup func1
#pragma exit func2

// funciona no GCC
void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();


void func1() {
    printf("Dentro da func1()\n");
}

void func2() {
    printf("Dentro da func2()\n");
}

int main() {
    printf("Dentro do main()\n");
    return 0;
}