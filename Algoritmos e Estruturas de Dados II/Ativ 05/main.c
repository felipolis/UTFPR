#include <stdio.h>
#include <stdlib.h>
#include "hashtable_ed.h"
#include "ilist.h"

//--------------------------------------------EX A --------------------------------------------
unsigned int random_32bits(){
    unsigned int x;
    x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    return x;
}

THED* inserir_n_aleatorios(int n, int m, int seed){
    THED* th = THED_Criar(m, 10);
    int max = 10*n;
    srand(seed);

    for(int i = 0; i <= max; i++){
        int x = random_32bits() % max;
        THED_Inserir(th, x, x);
    }
    return th;
}

//--------------------------------------------EX B --------------------------------------------


int THED_MaisLonga(THED* TH){
    int maior = 0;
    for(int i = 0; i < TH->m; i++){
        if(TH->t[i] != NULL){
            int tamanho = TH->t[i]->tam;
            if(tamanho > maior){
                maior = tamanho;
            }
        }
    }
    return maior;
}

int THED_MaisCurta(THED* TH){
    int menor = 0;
    for(int i = 0; i < TH->m; i++){
        if(TH->t[i] != NULL){
            int tamanho = TH->t[i]->tam;
            if(tamanho < menor){
                menor = tamanho;
            }
        }
    }
    return menor;
}

float THED_TamMedio(THED* TH){
    int soma = 0;
    int n = 0;
    for(int i = 0; i < TH->m; i++){
        if(TH->t[i] != NULL){
            int tamanho = TH->t[i]->tam;
            soma += tamanho;
            n++;
        }
    }
    return (float)soma/n;
}






//-------------------------------------------- MAIN --------------------------------------------

int main(){

    int n = 1000;
    int m = 10;

    THED* th = inserir_n_aleatorios(n, m, 42);

    //for(int i = 0; i < th->m; i++){
    //    printf("%d: ", i);
    //    ILIST_Imprimir(th->t[i], 1);
    //}

    int longa = THED_MaisLonga(th);
    printf("\nMais longa: %d\n", longa);
    
    int curta = THED_MaisCurta(th);
    printf("Mais curta: %d\n", curta);

    float medio = THED_TamMedio(th);
    printf("Tamanho medio: %f\n", medio);

    return 0;
}