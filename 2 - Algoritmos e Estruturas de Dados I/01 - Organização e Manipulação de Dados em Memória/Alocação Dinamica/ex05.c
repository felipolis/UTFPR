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

int* clone1(int *v, int tam){
    int* vetor_copia = (int*) calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor_copia[i] = v[i];
    }
    return vetor_copia;
}

bool clone2(int *v, int tam, int** saida){
    if(tam <= 0){
        return false;
    } else{
        int* vetor_copia = (int*) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            vetor_copia[i] = v[i];
        }
        *saida = vetor_copia;
        return true;
    }
}

int main(){

    int v[5] = {2,4,6,8,10};
    int *copia1, *copia2;

    copia1 = clone1(v, 5);
    clone2(v, 5, &copia2);

    imprimir_vetor(copia1, 5);
    imprimir_vetor(copia2, 5);

    return 0;
}