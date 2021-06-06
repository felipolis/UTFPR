#include <stdio.h>

//Funcao Ordem Crescente

int ordem(int *vet, int n){

    int i, j, aux;

    for(i = 0; i < n; i++){

        for(j = i + 1; j < n; j++){

            if(vet[i] > vet[j]){

                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

            }

        }

    }


}

//Funcao Main

int main(){

    int vetor[5], i;

    printf("=============================\n");
    printf("Digite valores nao ordenados!");
    printf("=============================\n\n");
    for(i = 0; i < 5; i++){
        
        printf("Digite um valor inteiro: ");
        scanf("%d", &vetor[i]);

    }

    printf("Vetor Desordenado: ");
    for(i = 0; i <5; i++){

        printf("%d\t", vetor[i]);

    }
    printf("\n\n");

    ordem(vetor, 5);

    printf("Vetor Ordenado: ");
    for(i = 0; i <5; i++){

        printf("%d\t", vetor[i]);

    }
    printf("\n\n");



    return 0;
}