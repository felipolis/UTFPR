#include <stdio.h>

///funcao fatorial

int fatorial(int n){

    int i, fat = 1;

    if(n >= 0){

        for(i = 1; i <= n; i++){

        fat = fat*i;

        }

        return fat;

    } else{

        return -1;

    }

    
}

///funcao main

int main(){

    int x;

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    printf("%d", fatorial(x));


    return 0;
}
