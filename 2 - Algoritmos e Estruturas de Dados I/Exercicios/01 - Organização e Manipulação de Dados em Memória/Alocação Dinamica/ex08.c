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

int** cria_matriz(int linhas, int colunas, int valor){
    int** m = (int**) calloc(linhas, sizeof(int*));
    for(int i = 0; i < linhas; i++){
        m[i] = (int*)calloc(colunas, sizeof(int));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            m[i][j] = valor;
        }
    }
    return m;
}

int main(){

    int** mat = cria_matriz(5, 6, -1);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            mat[i][j] = -1;
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}