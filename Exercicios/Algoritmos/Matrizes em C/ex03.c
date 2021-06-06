#include <stdio.h>

int main(){

    int A[10], B[10][3], i, j, menor;

    ///Lendo o vetor A

    for(i = 0; i < 10; i++){

        printf("Para o Vetor A, digite um numero inteiro: ");
        scanf(" %d", &A[i]);

    }

    printf("\n\n");

    ///Imprimindo o vetor A

    printf("VETOR A: ");

    for(i = 0; i < 10; i++){

        printf("%d \t", A[i]);

    }

    printf("\n\n");

    ///Descobrindo o menor elemento do vetor A

    menor = A[0];
    for(i = 0; i < 10; i++){

        if(A[i] < menor){
            menor = A[i];
        }

    }

    printf("O menor valor do vetor A eh %d \n\n", menor);

    ///Contruindo a matriz B

    for(i = 0; i < 10; i++){

        B[i][0] = A[i];

    }

    for(i = 0; i < 10; i++){

        B[i][1] = A[i] * A[i];

    }

    for(i = 0; i < 10; i++){

        B[i][2] = A[i] * menor;

    }

    ///Imprimindo a matriz B

    printf("MATRIZ B: \n\n");

    for(i = 0; i < 10; i++){
        for(j = 0; j < 3; j++){

            printf("%d \t", B[i][j]);

        }
        printf("\n");
    }

    return 0;

}