#include <stdio.h>

int main(){

    ///Declaração de variaveis

    int A[30];
    int B[30];
    int i;

    ///Lendo os numeros inteiros no vetor A

    for(i = 0; i < 30; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &A[i]);

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [ ");
    for(i = 0; i < 30; i++){

        printf("%d ", A[i]);

    }
    printf("]\n\n");

    ///Calculando o vetor B

    for(i = 0; i < 30; i++){

        B[i] = A[i] * A[i] * A[i];

    }

    ///Imprimindo o vetor B

    printf("Vetor B = [ ");
    for(i = 0; i < 30; i++){

        printf("%d ", B[i]);

    }
    printf("]\n\n");

    return 0;
}
