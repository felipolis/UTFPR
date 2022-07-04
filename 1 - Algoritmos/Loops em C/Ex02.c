#include <stdio.h>

int main(){

    int n, i;
    float s;

    printf("Digite um numero inteiro e positivo: ");
    scanf("%d", &n);


    for(i = 1; i <= n; i ++){
        s+= 1/(float)i;
    }


    printf("Soma total: %.2f", s);

    return 0;
}
