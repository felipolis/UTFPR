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

int* aleatorio1(int tam){
    int* vetor = (int*) calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 10;
    }
    return vetor;
}

bool aleatorio2(int tam, int** saida){
    if(tam < 0){
        return false;
    } else{
        int* vetor = (int*) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            vetor[i] = rand() % 10;
        }
        *saida = vetor;
        return true;
    }
}

int main(){

    srand(time(NULL));

    int *v1 = aleatorio1(10);
    int *v2;
    imprimir_vetor(v1, 5);

    aleatorio2(5, &v2);
    imprimir_vetor(v2, 5);

    return 0;
}