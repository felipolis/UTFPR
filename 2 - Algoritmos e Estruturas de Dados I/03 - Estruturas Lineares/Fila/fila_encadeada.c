#include "fila.h"
#include <string.h>
/**************************************
* DADOS
**************************************/
typedef struct no{
    int dado;
    struct no* prox;
}No;
struct fila {
    No* inicio;
    No* fim;
    int qtde;
};

No* cria_no(TipoElemento elemento){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = elemento;
	novo->prox = NULL;
	return novo;
}

bool fila_valida(Fila* f){
    return (f != NULL ? true : false);
}
/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->qtde = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
/*********************************************************/
void fila_destruir(Fila** enderecoFila){
    Fila* f = *enderecoFila;
    No* aux_memoria = NULL;

    for(int i = 0; i <= f->qtde; i++){
        aux_memoria = f->inicio;
        
        f->inicio = f->inicio->prox;
        free(aux_memoria);
    }
    free(f);
    *enderecoFila = NULL;
}
/*********************************************************/
bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_valida(f)) return false;

    No* novo = cria_no(elemento);

    if(f->qtde == 0){
        f->inicio = novo;
        f->fim = novo;
    } else{
        f->fim->prox = novo;
        f->fim = novo;
    }
    
    f->qtde++;

    return true;
}
/*********************************************************/
bool fila_remover(Fila* f, TipoElemento* saida){
    if(!fila_valida(f)) return false;
    if(f->qtde == 0) return false;

    TipoElemento retirado = f->inicio->dado;

    if(f->qtde == 1){
        free(f->inicio);
        f->inicio = NULL;
        f->fim = NULL;
    } else{
        No* aux_memoria = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux_memoria);
    }

    f->qtde--;

    *saida = retirado;
    return true;
}
/*********************************************************/
bool fila_primeiro(Fila* f, TipoElemento* saida){
    if(!fila_valida(f)) return false;

    *saida = f->inicio->dado;

    return true;
}
/*********************************************************/
bool fila_vazia(Fila* f){
    if(!fila_valida(f)) return false;

    return (f->qtde == 0 ? true : false);
}
/*********************************************************/
void fila_toString(Fila* f, char* saida){
    if(!fila_valida(f)) return;
	No* aux_memoria = f->inicio;

	saida[0] = '\0';
    strcat(saida, "[");
    while(aux_memoria != NULL){
        char elemento[200];
        sprintf(elemento, "%d", aux_memoria->dado);
        strcat(saida, elemento);
        if(aux_memoria->prox != NULL) strcat(saida, ",");
		aux_memoria = aux_memoria->prox;
    }
    strcat(saida, "]");
}