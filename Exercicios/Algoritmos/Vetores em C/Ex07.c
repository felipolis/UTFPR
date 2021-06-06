#include <stdio.h>

int main(){

    ///Declaracao de variaveis

    int A[5];
    int F[5];
    int i;
    int j;
    int fat;

    ///Lendo o vetor A

    for(i = 0; i < 5; i++){

        printf("Digite um numero inteiro nao negativo: ");
        scanf("%d", &A[i]);

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [");
    for(i = 0; i < 5; i++){

        printf(" %d", A[i]);

    }
    printf(" ]\n\n");

    ///Calculo do fatorial

    for(i = 0; i < 5; i++){

        fat = 1;

        for(j = 1; j <= A[i]; j++){
            fat = fat * j;
        }

        F[i] = fat;

    }

    ///Imprimindo o vetor F

    printf("Vetor F = [");
    for(i = 0; i < 5; i++){

        printf(" %d", F[i]);

    }
    printf(" ]\n\n");

    return 0;
}
