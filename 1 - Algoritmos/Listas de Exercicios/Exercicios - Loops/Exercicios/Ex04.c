#include <stdio.h>

int main(){

    int n, i, x = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    for(i=2 ; i <= n/2 ; i++){

        if(n % i == 0){

            x++;
            break;
        }

    }

    if (x == 0){

        printf("%d eh um numero primo\n", n);

    } else{

        printf("%d nao eh um numero primo\n", n);
    }

    return 0;
}
