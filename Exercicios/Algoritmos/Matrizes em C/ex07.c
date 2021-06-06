#include <stdio.h>

int main(){

    int M[2][4], i, j, quant = 0, soma = 0;
    float media;

    ///Lendo os valores da matriz M

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){

            printf("Para a matriz M, digite um numero inteiro: ");
            scanf("%d", &M[i][j]);

        }
    }

    ///Imprimindo os valores da matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Media dos elementos pares da matriz

    for(i = 0; i < 2; i++){
        for(j = 0; j < 4; j++){

            if(M[i][j] % 2 == 0){
                quant++;
                soma += M[i][j];
            }

        }
    }

    media = (float)soma/quant;

    printf("A media dos elementos pares da matriz M eh: %.2f", media);

    return 0;

}