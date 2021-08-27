#include <stdio.h>

int main(){

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int* v[4] = {&a, &b, &c, &d};
    int** p = v;

    printf("----------------\n");

    printf("%d\n", p);
    printf("%d\n", *p);
    printf("%d\n", **p);
    printf("%d\n", p[1]);
    printf("%d\n", *p[1]);
    printf("%d\n", **(p+2));
    printf("%d\n", v);
    printf("%d\n", v[3]);
    printf("%d\n", *(v+3));
    printf("%d\n", **(v+3));

    printf("----------------\n");

    printf("%d\n", **p);
    printf("%d\n", **(p+1));
    printf("%d\n", **(p+2));
    printf("%d\n", **(p+3));


    return 0;
}