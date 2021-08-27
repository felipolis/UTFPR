#include "lista.h"


/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no* ant;
	struct no *prox;
}No;

struct lista{
	No* sentinela;
	int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* cria_no(TipoElemento elemento){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = elemento;
	novo->ant = NULL;
    novo->prox = NULL;
	return novo;
}

No* devolver_enderecoNo(Lista* l, int posicao){
    No* aux = l->sentinela;
    for (int i=0; i <= posicao; i++) aux = aux->prox;
    return aux;
}

void insere_direita(No* referencia, No* no){
    no->prox = referencia->prox;
    no->ant = referencia;
    referencia->prox->ant = no;
    referencia->prox = no;
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->sentinela = (No*) malloc(sizeof(No));
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
    l->qtde = 0;
    return l;
}
/*************************************/
void lista_destruir(Lista** endereco){
    Lista* l = *endereco;
    TipoElemento elemento;

    for(int i = l->qtde-1; l->sentinela->prox != l->sentinela; i--){
        lista_removerPosicao(l,i,&elemento);
    }

    free(l->sentinela);
    free(*endereco);
}
/*************************************/
bool lista_anexar(Lista* l, TipoElemento elemento){
    if(l == NULL) return false;

    int posicao = l->qtde;
    No* novo = cria_no(elemento);
    No* aux = devolver_enderecoNo(l, posicao-1);
    insere_direita(aux, novo);

    l->qtde++;
    return true;
}
/*************************************/
bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(l == NULL) return false;
    if(posicao > l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    No* novo = cria_no(elemento);
    No* aux = devolver_enderecoNo(l, posicao-1);
    insere_direita(aux, novo);

    l->qtde++;
    return true;
}

/*************************************/

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(l == NULL) return false;
    if(posicao >= l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    No* aux = devolver_enderecoNo(l, posicao);

    *endereco = aux->dado;

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    l->qtde--;
    
    return true;
}
/*************************************/
int lista_removerElemento(Lista* l, TipoElemento elemento){
    if(l == NULL) return -1;
    
    int pos = lista_posicao(l, elemento);
    if(pos == -1) return -1;

    No* aux = devolver_enderecoNo(l, pos);

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    l->qtde--;
    
    return pos;
}

/*************************************/
bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if(l == NULL) return false;
    if(posicao >= l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    No* aux = devolver_enderecoNo(l, posicao);
    aux->dado = novoElemento;

    return true;
}
/*************************************/
int lista_posicao(Lista* l, TipoElemento elemento){
    if(l == NULL) return -1;
    int pos = -1;

    No* aux = l->sentinela;
    for(int i = 0; i < l->qtde; i++){

        aux = aux->prox;

        if(aux->dado == elemento){
            pos = i;
            break;
        }

    }

    return pos;
}
/*************************************/
bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(l == NULL) return false;
    if(posicao >= l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    No* aux = devolver_enderecoNo(l, posicao);

    *endereco = aux->dado;

    return true;
}
/*************************************/
int lista_tamanho(Lista* l){
    if(l == NULL) return -1;
    return l->qtde;
}
/*************************************/
bool lista_vazia(Lista* l){
    if(l == NULL) return false;

    return (l->qtde == 0 ? true : false);
}
/*************************************/
bool lista_toString(Lista* l, char* str){
    if(l == NULL) return false;

    No* aux = l->sentinela->prox;

	str[0] = '\0';
    strcat(str, "[");

    while(aux != l->sentinela){
        char elemento[200];
        sprintf(elemento, "%d", aux->dado);
        strcat(str, elemento);
        if(aux->prox != l->sentinela) strcat(str, ",");
		aux = aux->prox;
    }
    strcat(str, "]");
}