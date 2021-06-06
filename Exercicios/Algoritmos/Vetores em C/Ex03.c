#include <stdio.h>

int main(){

    ///Declaração de variaveis

    int A[25];
    int i;
    int maior;
    int menor;

    ///Lendo os numeros inteiros no vetor A

    for(i = 0; i < 25; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &A[i]);

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [ ");
    for(i = 0; i < 25; i++){

        printf("%d ", A[i]);

    }
    printf("]\n\n");

    ///Calculo e Impressao do Maior Valor

    maior = A[0];
    for(i = 0; i < 25; i++){

        if(A[i] > maior){
            maior = A[i];
        }

    }

    printf("Maior valor do vetor A: %d \n\n", maior);

    ///Calculo e Impressao do Menor Valor

    menor = A[0];
    for(i = 0; i < 25; i++){

        if(A[i] < menor){
            menor = A[i];
        }

    }

    printf("Menor valor do vetor A: %d \n\n", menor);


    return 0;
}
