#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void imprimir_vetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i<tam-1) printf(",");
    }
    printf("]");
}

int dobra_tamanho(int** v, int tam){
    int* vetor = (int*) calloc(tam*2, sizeof(int));
    for(int i = 0; i < tam*2; i++){
        if(i<tam){
            vetor[i] = *(*v + i);
        } else{
            vetor[i] = 0;
        }
    }
    free(*v);
    *v = vetor;
    return tam*2;
}

int main(){

    int* v = (int*) calloc(3, sizeof(int));
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;

    int novoTamanho = dobra_tamanho(&v,3);
    imprimir_vetor(v, 6);

    return 0;
}