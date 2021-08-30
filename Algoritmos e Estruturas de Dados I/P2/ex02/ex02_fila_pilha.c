#include "fila.h"
#include "pilha.h"
#include "string.h"

/**************************************
* DADOS
**************************************/

struct fila {
    Pilha* p1;
    Pilha* p2;    
    int qtde;
};

void p1TOp2(Fila* f){
    TipoElemento aux;
    int tamP1 = pilha_tamanho(f->p1);
    for(int i = 0; i < tamP1; i++){
        pilha_desempilhar(f->p1, &aux);
        pilha_empilhar(f->p2, aux);
    }
}

void p2TOp1(Fila* f){
    TipoElemento aux;
    int tamP2 = pilha_tamanho(f->p2);
    for(int i = 0; i < tamP2; i++){
        pilha_desempilhar(f->p2, &aux);
        pilha_empilhar(f->p1, aux);
    }
}

/**************************************
* Exercício
**************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->p1 = pilha_criar();
    f->p2 = pilha_criar();
    f->qtde = 0;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(fila_vazia(f)){
        pilha_empilhar(f->p1, elemento);
    } else{
        p1TOp2(f);
        pilha_empilhar(f->p2, elemento);
        p2TOp1(f);
    }
    f->qtde++;
}


void fila_destruir(Fila** enderecoFila){
    Fila* f = *enderecoFila;
    free(f->p1);
    free(f->p2);
    free(*enderecoFila);
    *enderecoFila = NULL;
}



bool fila_remover(Fila* f, TipoElemento* saida){
    pilha_desempilhar(f->p1, saida);
    f->qtde--;
}


bool fila_primeiro(Fila* f, TipoElemento* saida){
    pilha_topo(f->p1, saida);
}

bool fila_vazia(Fila* f){
    return (f->qtde == 0 ? true : false);
}

bool fila_toString(Fila* f, char* saida){
    pilha_toString(f->p1, saida);
}