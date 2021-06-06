#include <stdio.h>

//funcao de invercao

void inv(int *vet, int tam){

    int i, aux;

    for(i = 0; i < 10/2; i++){

        aux = vet[i];
        vet[i] = vet[10 - 1 - i];
        vet[10 - 1 - i] = aux;

    }

    printf("Vetor Invertido: ");
    for(i = 0; i < 10; i++){

        printf("%d\t", vet[i]);

    }
    printf("\n\n");
}

//funcao main

int main(){

    int vetor[10], i;

    //Recebendo os valores do vetor

    for(i = 0; i < 10; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &vetor[i]);

    }
    printf("\n\n");

    //Imprimindo o vetor recebido do usuario

    printf("Vetor Recebido do usuario: ");
    for(i = 0; i < 10; i++){

        printf("%d\t", vetor[i]);

    }
    printf("\n\n");

    //chamando a funcao de invercao

    inv(vetor, 10);




    return 0;
}