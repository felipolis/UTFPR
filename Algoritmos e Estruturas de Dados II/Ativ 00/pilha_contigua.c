#include "pilha.h"

#define TAM_INICIAL 5

struct pilha {
    int qtde;
    int tam;
    TipoElemento* vetor;
};



void verifica_aumenta(Pilha* p){
    if(p->qtde == p->tam){
        TipoElemento* novo_vetor = (TipoElemento*) calloc(p->tam*2, sizeof(TipoElemento));

        for(int i = 0; i < p->tam; i++){
            novo_vetor[i] = p->vetor[i];
        }

        p->tam *= 2;
        free(p->vetor);
        p->vetor = novo_vetor;

    }
}

void verifica_diminui(Pilha* p){
    int quant = p->qtde;
    int tam = p->tam;
    float taxa_ocupacao = (float)quant/tam;

    if(taxa_ocupacao < 0.25){
        TipoElemento* novo_vetor = (TipoElemento*) calloc(p->tam/2, sizeof(TipoElemento));

        for(int i = 0; i < p->qtde; i++){
            novo_vetor[i] = p->vetor[i];
        }

        p->tam /= 2;
        free(p->vetor);
        p->vetor = novo_vetor;
    }
}

bool pilha_valida(Pilha* p){
    return (p != NULL ? true : false);
}

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    p->tam = TAM_INICIAL;
    p->qtde = 0;
    return p;
}


void pilha_destruir(Pilha** endereco){
    Pilha* p = *endereco;
    if(!pilha_valida(p)) return;

    free(p->vetor);
    free(p);
    *endereco = NULL;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
    if(!pilha_valida(p)) return false;

    verifica_aumenta(p);
    p->vetor[p->qtde++] = elemento;
    return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){
    if(!pilha_valida(p)) return false;

    verifica_diminui(p);
    *saida = p->vetor[p->qtde-1];
    p->qtde--;
    return true;
}


bool pilha_topo(Pilha* p, TipoElemento* saida){
    if(!pilha_valida(p)) return false;

    *saida = p->vetor[p->qtde-1];
    return true;
}

bool pilha_vazia(Pilha* p){
    if(!pilha_valida(p)) return false;
    return (p->qtde == 0 ? true : false);
}

int pilha_quantidade(Pilha* p){
	return p->qtde;
}

void pilha_toString(Pilha* p, char* saida){
    if(!pilha_valida(p)) return;

    saida[0] = '\0';
    strcat(saida, "[");
    for (int i=p->qtde-1; i >= 0; i--){
        char elemento[200];
        sprintf(elemento, "%d", p->vetor[i]);
        strcat(saida, elemento);
        if(i > 0) strcat(saida, ",");
    }
    strcat(saida, "]");
}