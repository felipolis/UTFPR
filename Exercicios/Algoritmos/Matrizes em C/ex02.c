#include <stdio.h>

int main(){

    int V1[7], V2[7], M[7][2];
    int i, j;

    ///Lendo o vetor 1

    for(i = 0; i < 7; i++){

        printf("Para o Vetor 1, digite um numero inteiro: ");
        scanf(" %d", &V1[i]);

    }

    printf("\n\n");

    ///Lendo o vetor 2

    for(i = 0; i < 7; i++){

        printf("Para o Vetor 2, digite um numero inteiro: ");
        scanf(" %d", &V2[i]);

    }

    printf("\n\n");

    ///Imprimindo o vetor 1

    printf("VETOR 1: ");

    for(i = 0; i < 7; i++){

        printf("%d \t", V1[i]);

    }

    printf("\n\n");

    ///Imprimindo o vetor 2

    printf("VETOR 2: ");

    for(i = 0; i < 7; i++){

        printf("%d \t", V2[i]);

    }

    printf("\n\n");

    ///Contruindo a matriz M

    for(i = 0; i < 7; i++){

        M[i][0] = V1[i];

    }

    for(i = 0; i < 7; i++){

        M[i][1] = V2[i];

    }
    
    ///Imprimindo a matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 7; i++){
        for(j = 0; j < 2; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");





    return 0;
}