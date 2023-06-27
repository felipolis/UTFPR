#include <stdio.h>

int main(){

    ///Declaração de variaveis

    int A[10];
    int i;
    int n;
    int verif = 0;

    ///Lendo os numeros inteiros no vetor A

    for(i = 0; i < 10; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &A[i]);

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [ ");
    for(i = 0; i < 10; i++){

        printf("%d ", A[i]);

    }
    printf("]\n\n");

    ///Numero de verificacao

    printf("Digite um numero para fazer a verificacao dentro do vetor: ");
    scanf("%d", &n);

    for(i = 0; i < 10; i++){

        if(A[i] == n){

            verif++;

        }

    }

    printf("O numero %d possui %d copias no vetor!\n\n\n", n, verif);



    return 0;
}
