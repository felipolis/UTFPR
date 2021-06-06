#include <stdio.h>

int main(){

    int A[5][4], B[4][3], C[5][3], i, j, k, aux = 0;

    ///Lendo os valores da matriz A

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){

            printf("Para a matriz A, digite um numero inteiro: ");
            scanf("%d", &A[i][j]);

        }
    }

    ///Lendo os valores da matriz B

    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){

            printf("Para a matriz B, digite um numero inteiro: ");
            scanf("%d", &B[i][j]);

        }
    }

    ///Imprimindo os valores da matriz A

    printf("MATRIZ A: \n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){

            printf("%d \t", A[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Imprimindo os valores da matriz B

    printf("MATRIZ B: \n\n");

    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){

            printf("%d \t", B[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///(Mult. de matrizes) Construindo a matriz C

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){

            C[i][j] = 0;
            for(k = 0; k < 4; k++){

                aux += A[i][k] * B[k][j];

            }

            C[i][j] = aux;
            aux = 0; 

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

}