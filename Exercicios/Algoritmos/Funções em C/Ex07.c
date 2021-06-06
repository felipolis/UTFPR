#include <stdio.h>

//Funcao capicua

int capicua(int num){

    int resto, numInv = 0, aux;

    aux = num;
    while(aux > 0){

        resto = aux % 10;
        aux = aux / 10;
        numInv = (numInv * 10) + resto;

    }

    if(numInv == num){

        return 1;

    } else{

        return 0;

    }

}

//Funcao main

int main(){

    int x;

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    printf("%d", capicua(x));

    return 0;
}