#include <stdio.h>

int main(){

    int v[4] = {1, 2, 3, 4};
    int i = 30;

    int* p = v;
    int* w = v + 2;
    int* x = &i;

    printf("----------------\n");

    printf("%d\n", p);
    printf("%d\n", v);
    printf("%d\n", &v[0]);
    printf("%d\n", v+1);
    printf("%d\n", *(v+2));
    printf("%d\n", w);
    printf("%d\n", *w);
    printf("%d\n", w[1]);
    printf("%d\n", x);
    printf("%d\n", &x);
    printf("%d\n", *x);
    printf("%d\n", x[0]);
    printf("%d\n", p+3);
    printf("%d\n", &p[3]);
    printf("%d\n", *(p+3));
    printf("%d\n", p[3]);

    printf("----------------\n");

    printf("%d \n", p[0]); //0
    printf("%d \n", *p);

    printf("%d \n", p[1]); //1
    printf("%d \n", *(p+1));

    printf("%d \n", p[2]); //2
    printf("%d \n", *(p+2));
    
    printf("%d \n", p[3]); //3
    printf("%d \n", *(p+3));


    return 0;
}