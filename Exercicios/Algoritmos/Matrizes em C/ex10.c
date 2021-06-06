#include <stdio.h>

int main(){

    int M[4][4], i, j;
    int somaDP = 0, somaDS = 0;
    int vetLinhas[4], vetColunas[4];
    int auxLinha = 1, auxColuna = 1;

    ///Lendo os valores da matriz M

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            printf("Para a matriz M, digite um numero inteiro: ");
            scanf("%d", &M[i][j]);

        }
    }

    ///Imprimindo os valores da matriz M

    printf("MATRIZ M: \n\n");

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){

            printf("%d \t", M[i][j]);

        }
        printf("\n");
    }

    printf("\n\n");

    ///Calculando a soma da diagonal principal

    for(i = 0; i < 4; i++){

        somaDP += M[i][i];

    }

    printf("Soma dos valores da diabonal principal: %d \n\n", somaDP);

    ///Calculando a soma da diagonal secudaria

    for(i = 0; i < 4; i++){

        somaDS += M[i][4 - 1 - i];

    }

    printf("Soma dos valores da diabonal secundaria: %d \n\n", somaDS);

    ///Calculando a soma das linhas

    for(i = 0; i < 4; i++){

        vetLinhas[i] = 0;
        for(j = 0; j < 4; j++){

            vetLinhas[i] += M[i][j];

        }
    }

    printf("Soma das Linhas: ");
    for(i = 0; i < 4; i++){
        printf("%d \t", vetLinhas[i]);
    }
    printf("\n\n");

    ///Calculando a soma das colunas

    for(j = 0; j < 4; j++){

        vetColunas[j] = 0;
        for(i = 0; i < 4; i++){

            vetColunas[j] += M[i][j];

        }
    }

    printf("Soma das Colunas: ");
    for(i = 0; i < 4; i++){
        printf("%d \t", vetColunas[i]);
    }
    printf("\n\n");

    ///

    for(i = 1; i < 4; i++){

        if(vetLinhas[i] != vetLinhas[i-1]){

            auxLinha = 0;
            break;

        } else if(vetColunas[i] != vetColunas[i - 1]){

            auxColuna = 0;
            break;

        }

    }

    if (auxLinha && auxColuna && somaDP == somaDS && somaDP == vetLinhas[0]) {
		printf("Se trata de um Quadrado magico!");
	} else {
		printf("Se trata de um Quadrado nao magico");
	}





    return 0;

}