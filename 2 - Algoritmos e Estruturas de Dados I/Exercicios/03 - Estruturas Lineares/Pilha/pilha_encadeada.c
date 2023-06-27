#include "pilha.h"

typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct pilha{
	int qtde;
    No *topo;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* cria_no(TipoElemento elemento){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = elemento;
	novo->prox = NULL;
	return novo;
}

bool pilha_valida(Pilha* p){
    return (p != NULL ? true : false);
}

/**************************************
* PROTÓTIPOS
**************************************/

Pilha* pilha_criar(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->qtde = 0;
    p->topo = NULL;
    return p;
}
/*********************************************************/
void pilha_destruir(Pilha** endereco){
	Pilha* p = *endereco;
	No* aux_memoria = NULL;

	for(int i = 0; i <= p->qtde; i++){
		aux_memoria = p->topo->prox;

		free(p->topo);
		p->topo = aux_memoria;
	}

	free(p);
	*endereco = NULL;
}
/*********************************************************/
bool pilha_empilhar(Pilha* p, TipoElemento elemento){
	if(!pilha_valida(p)) return false;

	No* novo = cria_no(elemento);
	novo->prox = p->topo;
	p->topo = novo;
	p->qtde++;

	return true;
}
/*********************************************************/
bool pilha_desempilhar(Pilha* p, TipoElemento* saida){
	if(!pilha_valida(p)) return false;

	TipoElemento retirado = p->topo->dado;

	No* aux_memoria = p->topo;

	p->topo = p->topo->prox;
	p->qtde--;

	free(aux_memoria);

	*saida = retirado;
	return true;
}
/*********************************************************/
bool pilha_topo(Pilha* p, TipoElemento* saida){
	if(!pilha_valida(p)) return false;

	*saida = p->topo->dado;

	return true;
}
/*********************************************************/
bool pilha_vazia(Pilha* p){
	if(!pilha_valida(p)) return false;

	return (p->qtde == 0 ? true : false);
}
/*********************************************************/
void pilha_toString(Pilha* p, char* saida){
	if(!pilha_valida(p)) return;
	No* aux_memoria = p->topo;

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