#include <stdio.h>

int main(){

    int n;
    int t1 = 0, t2 = 1, t3;
    int i;

    printf("Quantos termos voce quer mostrar?");
    scanf("%d", &n);

    printf("%d, %d, ",t1, t2);

    i = 3;
    while(i <= n){

        t3 = t1 + t2;
        printf("%d, ",t3);
        t1 = t2;
        t2 = t3;
        i++;

    }

    return 0;
}
