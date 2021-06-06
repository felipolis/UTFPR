#include <stdio.h>

int main(){

    ///Declaracao de variaveis

    float A[10];
    float B[10];
    float C[10];
    int i, j;

    ///Lendo o vetor A

    for(i = 0; i < 10; i++){

        printf("Digite um numero real diferente de 0 para o vetor A: ");
        scanf("%f", &A[i]);
        C[i] = A[i];

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [");
    for(i = 0; i < 10; i++){

        printf(" %.2f", A[i]);

    }
    printf(" ]\n\n");

    ///Lendo o vetor B

    for(i = 0; i < 10; i++){

        printf("Digite um numero real diferente de 0 para o vetor B: ");
        scanf("%f", &B[i]);
        C[i + 10] = B[i];

    }

    ///Imprimindo o vetor B

    printf("Vetor B = [");
    for(i = 0; i < 10; i++){

        printf(" %.2f", B[i]);

    }
    printf(" ]\n\n");

    ///Calculo da Uniao dos vetores

    for(i = 0; i < 20; i++){

        for(j = i + 1; j < 20; j++){

            if(C[i] == C[j]){

                C[j] = 0;

            }

        }

    }

    ///Imprimindo a uniao dos vetores

    printf("Vetor C = [");
    for(i = 0; i < 20; i++){

        if(C[i] != 0){

            printf(" %.2f", C[i]);

        }

    }
    printf(" ]\n\n");





    return 0;
}
