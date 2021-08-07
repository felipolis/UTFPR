#include <stdio.h>

int main(){

    int n;
    int i;

    printf("Digite um numero entre 1 - 10: ");
    scanf("%d", &n);

    for ( i = 1; i <= 10; i++)
    {
        printf("%d X %d = %d \n", n, i, n*i );
    }

    return 0;
}
