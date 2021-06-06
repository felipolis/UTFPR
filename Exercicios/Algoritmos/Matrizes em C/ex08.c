#include <stdio.h>

int main(){

    int M[12][4], i, j;
    float soma;

    ///Lendo os valores da matriz M

    for(i = 0; i < 12; i++){
        for(j = 0; j < 4; j++){

            printf("Para a matriz M, digite um numero inteiro: ");
            scanf("%d", &M[i][j]);

        }
    }

    ///Imprimindo os valores da matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 12; i++){
        for(j = 0; j < 4; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Total vendido em cada mes do ano

    for(i = 0; i < 12; i++){

        soma = 0;
        for(j = 0; j < 4; j++){

            soma += M[i][j];

        }

        printf("O total vendido no mes %d foi de R$ %.2f \n", i, soma);

    }

    printf("\n\n");



    ///O total vendido em cada semana durante todo o ano

    for(j = 0; j < 4; j++){

        soma = 0;
        for(i = 0; i < 12; i++){

            soma += M[i][j];

        }

        printf("O total vendido na semana %d foi de R$ %.2f durante todo o ano \n", j, soma);

    }

    printf("\n\n");



    ///O total vendido pela loja no ano

    soma = 0;

    for(i = 0; i < 12; i++){
        for(j = 0; j < 4; j++){

            soma += M[i][j];

        }
    }

    printf("O total vendido no ano foi de R$ %.2f \n", soma);
    printf("\n\n");

    return 0;

}