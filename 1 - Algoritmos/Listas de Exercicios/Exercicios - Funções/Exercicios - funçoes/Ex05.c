#include <stdio.h>

///funcao primo

int primo(int n){

    int i, aux;

    for(i=2 ; i <= n/2 ; i++){

        if(n % i == 0){

            aux++;
            break;
        }

    }

    if (aux == 0){

        return 1;

    } else{

        return -1;
    }

}

///funcao main

int main(){

    int x;

    printf("Digite um numero inteiro e positivo: ");
    scanf("%d", &x);

    printf("%d", primo(x));


    return 0;
}
