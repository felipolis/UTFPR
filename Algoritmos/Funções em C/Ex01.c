#include <stdio.h>

///Prototipos de funcao

dobro(int n);

///Funcao main

int main(){
    
    ///Declaracao de variaveis

    int x, aux;

    ///Recebendo um valor inteiro

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    ///Atribuindo valor retornado da funcao

    aux = dobro(x);

    ///Imprimindo o dobro do valor

    printf("O dobro de %d eh %d", x, aux);

    return 0;
}

///Funcao dobro

int dobro(int n){

    return 2*n;

}