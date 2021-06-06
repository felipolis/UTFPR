#include <stdio.h>

int main(){

    int M[3][5], i, j, cont = 0;

    ///Lendo os valores da matriz M

    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){

            printf("Para a matriz M, digite um numero inteiro: ");
            scanf("%d", &M[i][j]);

        }
    }

    ///Imprimindo os valores da matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Contagem dos elementos

    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){

            if(M[i][j] >= 15 && M[i][j] <= 20){

                cont++;

            }

        }
    }

    printf("A quantidade de elementos entre 15 e 20 eh %d", cont);




    return 0;
}