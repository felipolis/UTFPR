#include <stdio.h>

int main(){

    ///Declaracao de variaveis

    float A[50];
    float soma, media;
    int verif = 0;
    int i;

    ///Lendo o vetor A

    for(i = 0; i < 50; i++){

        printf("Digite um numero real diferente de 0 para o vetor A: ");
        scanf("%f", &A[i]);
    }

    ///Imprimindo o vetor A

    printf("\n\nVetor A = [");
    for(i = 0; i < 50; i++){

        printf(" %.2f", A[i]);

    }
    printf(" ]\n\n");

    ///Calculo da Media aritmetica

    soma = 0;

    for(i = 0; i < 50; i++){

        soma = soma + A[i];

    }

    media = (float)soma/50;

    ///Imprimindo a media aritmetica

    printf("Media = %.2f \n\n", media);

    ///Verificacao no vetor

    for(i = 0; i < 20; i++){

        if(A[i] > media){

            verif++;

        }

    }

    ///Quantidade de valores acima da media aritmetica

    printf("Ha %d valores no vetor que estao acima da media aritmetica!\n\n", verif);

    return 0;
}
