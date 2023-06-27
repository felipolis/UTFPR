#include <stdio.h>

int main(){

    int v1[3] = {1, 2, 3};
    int v2[3] = {4, 5, 6};

    int* p1 = v1;
    int* p2 = v2;
    int* m[2] = {v1, v2};

    int** pm = m;

    printf("----------------\n");

    printf("p1: %d\n", p1);
    printf("v1: %d\n", v1);
    printf("p1+2: %d\n", p1+2);
    printf("v1+2: %d\n", v1+2);
    printf("p2[1]: %d\n", p2[1]);
    printf("*(v2+1): %d\n", *(v2+1));
    printf("m: %d\n", m);
    printf("*m: %d\n", *m);
    printf("pm: %d\n", pm);
    printf("*pm: %d\n", *pm);
    printf("m[0]: %d\n", m[0]);
    printf("*(m+1): %d\n", *(m+1));
    printf("*pm[1]: %d\n", *pm[1]);
    printf("**(m+1): %d\n", **(m+1));
    printf("m[0][2]: %d\n", m[0][2]);
    printf("pm: %d\n", pm);
    printf("pm+1: %d\n", pm+1);
    printf("*(pm+1)+2: %d\n", *(pm+1)+2);
    printf("*(*(pm+1)+2): %d\n", *(*(pm+1)+2));

    printf("----------------\n");

    // valor 1
    printf("%d\n", m[0][0]);
    printf("%d\n", **pm);
    printf("%d\n", **m);
    printf("%d\n", v1[0]);
    printf("%d\n", *pm[0]);
    printf("%d\n", *(v1));
    printf("%d\n", p1[0]);

    // valor 2
    printf("%d\n", p1[1]);
    printf("%d\n", v1[1]);
    printf("%d\n", *(v1+1));
    printf("%d\n", *(pm[0]+1));
    printf("%d\n", m[0][1]);
    printf("%d\n", *(*m+1));
    printf("%d\n", *(*pm+1));

    // valor 3
    printf("%d\n", p1[2]);
    printf("%d\n", v1[2]);
    printf("%d\n", *(v1+2));
    printf("%d\n", *(pm[0]+2));
    printf("%d\n", m[0][2]);
    printf("%d\n", *(*m+2));
    printf("%d\n", *(*pm+2));

    // valor 4
    printf("%d\n", p2[0]);
    printf("%d\n", v2[0]);
    printf("%d\n", *(v2));
    printf("%d\n", *pm[1]);
    printf("%d\n", m[1][0]);
    printf("%d\n", **(m+1));
    printf("%d\n", **(pm+1));

    // valor 5
    printf("%d\n", p2[1]);
    printf("%d\n", v2[1]);
    printf("%d\n", *(v2+1));
    printf("%d\n", *(pm[1]+1));
    printf("%d\n", m[1][1]);
    printf("%d\n", *(*(m+1)+1));
    printf("%d\n", *(*(pm+1)+1));

    // valor 6
    printf("%d\n", p2[2]);
    printf("%d\n", v2[2]);
    printf("%d\n", *(v2+2));
    printf("%d\n", *(pm[1]+2));
    printf("%d\n", m[1][2]);
    printf("%d\n", *(*(m+1)+2));
    printf("%d\n", *(*(pm+1)+2));

    return 0;
}