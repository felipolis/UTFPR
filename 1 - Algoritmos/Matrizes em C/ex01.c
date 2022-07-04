#include <stdio.h>

int main(){

    int A[5][3], B[5][3], C[5][3];
    int i, j;

    ///Lendo os valores da matriz A

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            printf("Para a matriz A, digite um numero inteiro: ");
            scanf("%d", &A[i][j]);

        }
    }

    ///Lendo os valores da matriz B

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            printf("Para a matriz B, digite um numero inteiro: ");
            scanf("%d", &B[i][j]);

        }
    }

    ///Imprimindo os valores da matriz A

    printf("MATRIZ A: \n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            printf("%d \t", A[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Imprimindo os valores da matriz B

    printf("MATRIZ B: \n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            printf("%d \t", B[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Contruindo a matriz C

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            C[i][j] = A[i][j] + B[i][j];

        }
    }

    ///Imprimindo os valores da matriz C

    printf("MATRIZ C: \n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            printf("%d \t", C[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");


    return 0;
}