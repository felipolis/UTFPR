#include <stdio.h>

int main(){

    ///Declaração de variaveis

    int A[5];
    int B[5];
    int C[10];
    int i;
    int aux;
    int j;

    ///Lendo os numeros inteiros no vetor A

    printf("Digite uma sequencia de numeros inteiros, nao necessariamente em ordem, para o conjunto de numeros A[]!\n\n");

    for(i = 0; i < 5; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &A[i]);

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [ ");
    for(i = 0; i < 5; i++){

        printf("%d ", A[i]);

    }
    printf("]\n\n");

    ///Lendo os numeros inteiros no vetor b

    printf("Digite uma sequencia de numeros inteiros, nao necessariamente em ordem, para o conjunto de numeros B[]!\n\n");

    for(i = 0; i < 5; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &B[i]);

    }

    ///Imprimindo o vetor B

    printf("Vetor B = [ ");
    for(i = 0; i < 5; i++){

        printf("%d ", B[i]);

    }
    printf("]\n\n");

    ///Preenchimento do vetor C

    for(i = 0; i < 5; i++){

        C[i] = A[i];
        C[i + 5] = B[i];

    }


    ///Imprimindo o vetor C desordenado

    printf("Vetor C = [");
    for(i = 0; i < 10; i++){

        printf(" %d", C[i]);

    }
    printf(" ]\n\n");

    ///Ordenamento em ordem crescente

    for(i = 0; i < 10; i++){

        for(j = i + 1; j < 10; j++){

            if(C[i] > C[j]){

                aux = C[i];
                C[i] = C[j];
                C[j] = aux;

            }

        }

    }

    ///Imprimindo o vetor C

    printf("Vetor C = [");
    for(i = 0; i < 10; i++){

        printf(" %d", C[i]);

    }
    printf(" ]\n\n");



    return 0;
}
