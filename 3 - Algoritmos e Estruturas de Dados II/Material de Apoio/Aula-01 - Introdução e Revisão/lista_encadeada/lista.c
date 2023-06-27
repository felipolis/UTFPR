#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

LISTA* LISTA_Criar(){
    LISTA* nova;

    nova = (void*) malloc(sizeof(LISTA));

    nova->primeiro = NULL;
    nova->ultimo = NULL;
    nova->tam = 0;

    return nova;
}

void LISTA_Inserir(LISTA *L, int dado){
    LISTA_NO* novo;
    novo = malloc(sizeof(LISTA_NO));
    
    novo->dado = dado;
    novo->prox = NULL;

    if(LISTA_Vazia(L)){
        L->primeiro = novo;
    }
    else{
        L->ultimo->prox = novo;
    }

    L->ultimo = novo;
    L->tam++;
}

LISTA_NO* LISTA_Buscar(LISTA *L, int dado){

}

bool LISTA_Vazia(LISTA *L){
    return (L->tam == 0);
}

int LISTA_Tamanho(LISTA *L){
    return L->tam;
}

void LISTA_Imprimir(LISTA *L){
    LISTA_NO* p = L->primeiro;

    while(p != NULL){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("\n");
}

void LISTA_Destruir(LISTA *L){

}

bool LISTA_Remover(LISTA *L, int dado){

}