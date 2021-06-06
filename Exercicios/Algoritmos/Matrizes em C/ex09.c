#include <stdio.h>

int main(){

    int M[6][4], N[6][4], i, j, maior;

    ///Lendo os valores da matriz M

    for(i = 0; i < 6; i++){
        for(j = 0; j < 4; j++){

            printf("Para a matriz M, digite um numero inteiro: ");
            scanf("%d", &M[i][j]);

        }
    }

    ///Imprimindo os valores da matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 6; i++){
        for(j = 0; j < 4; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Multiplicando as linhas pelo seus respectivos maiores elementos

    for(i = 0; i < 6; i++){

        maior = M[i][0];
        for(j = 0; j < 4; j++){

            if(M[i][j] > maior){
                maior = M[i][j];
            }
        }

        for(j = 0; j < 4; j++){
            N[i][j] = M[i][j] * maior;
        }

    }

    ///Imprimindo os valores da matriz N

    printf("MATRIZ M modificada: \n\n");

    for(i = 0; i < 6; i++){
        for(j = 0; j < 4; j++){

            printf("%d \t", N[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");


    return 0;

}