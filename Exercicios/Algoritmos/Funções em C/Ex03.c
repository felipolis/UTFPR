#include <stdio.h>
#include <math.h>

///Funcao calculo da raiz

float calculo(int n1, int n2){

    float conta = pow(n1, 1.0/n2);

    return conta;

}

///Funcao main

int main(){

    int indice, radicando;
    float raiz;

    printf("Digite o numero do radicando da raiz: ");
    scanf("%d", &radicando);

    printf("Digite o numero do indice da raiz: ");
    scanf("%d", &indice);

    
    printf("O valor da raiz de %d no indice %d eh %.2f", radicando, indice, calculo(radicando, indice));

    return 0;
}


