#include <stdio.h>

int main(){

    ///Declaracao de variaveis

    int A[30];
    int maior;
    int B[30];
    int i;

    ///Lendo o vetor A

    for(i = 0; i < 30; i++){

        printf("Digite um numero inteiro para o vetor A: ");
        scanf("%d", &A[i]);
    }

    ///Imprimindo o vetor A

    printf("\n\nVetor A = [");
    for(i = 0; i < 30; i++){

        printf(" %d", A[i]);

    }
    printf(" ]\n\n");

    ///Maior valor de A

    maior = A[0];
    for(i = 0; i < 30; i++){

        if(A[i] > maior){
            maior = A[i];
        }

    }

    ///Construindo vetor B

    for(i = 0; i < 30; i++){

        B[i] = A[i] * maior;


    }

    ///Imprimindo o vetor B

    printf("\n\nVetor B = [");
    for(i = 0; i < 30; i++){

        printf(" %d", B[i]);

    }
    printf(" ]\n\n");




    return 0;
}
