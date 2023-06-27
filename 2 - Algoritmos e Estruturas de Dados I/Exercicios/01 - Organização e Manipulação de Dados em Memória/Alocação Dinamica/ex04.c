#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimir_vetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i<tam-1) printf(",");
    }
    printf("]");
}

int* cria_vetor1(int tam, int valor){
    int* vetor = (int*) calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor[i] = valor;
    }
    return vetor;
}

bool cria_vetor2(int tam, int valor, int** saida){
    if(tam <= 0){
        return false;
    } else{
        int* vetor = (int*) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            vetor[i] = valor;
        }
        *saida = vetor;
        return true;
    }
}

int main(){

    int *v1, *v2;
    v1 = cria_vetor1(10, -1);
    cria_vetor2(5, 0, &v2);
    imprimir_vetor(v1, 10);
    imprimir_vetor(v2, 5);

    return 0;
}