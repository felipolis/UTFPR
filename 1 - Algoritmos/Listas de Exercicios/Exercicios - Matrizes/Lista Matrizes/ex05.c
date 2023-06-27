#include <stdio.h>

int main(){

    int M[5][5], i, j, maior, menor;

    ///Lendo os valores da matriz M

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){

            printf("Para a matriz M, digite um numero inteiro: ");
            scanf("%d", &M[i][j]);

        }
    }

    ///Imprimindo os valores da matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Descobrindo o menor valor de M

    menor = M[0][0];
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){

            if(M[i][j] < menor){

                menor = M[i][j];

            }

        }
    }

    printf("O menor elemento da matriz M eh %d \n\n", menor);


    ///Descobrindo o maior valor de M

    maior = M[0][0];
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){

            if(M[i][j] > maior){

                maior = M[i][j];

            }

        }
    }

    printf("O maior elemento da matriz M eh %d \n\n", maior);

    return 0;

}