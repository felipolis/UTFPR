#include "lista.h"


/*------------------------------------------------
Especificação dos dados
-------------------------------------------------*/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *sentinela;
	int qtde;
};

/*------------------------------------------------
FUNÇÕES AUXILIARES
-------------------------------------------------*/
No* criar_no(TipoElemento elemento){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = NULL;
    no->ant = NULL;
    return no;
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


/*------------------------------------------------
Implementação das funções
-------------------------------------------------*/

Lista* lista_criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->sentinela = (No*) malloc(sizeof(No));
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;

}

void lista_destruir(Lista** endereco);

bool lista_anexar(Lista* l, TipoElemento elemento);
bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){

    No* novo = criar_no(elemento);
    No* aux = devolver_enderecoNo(l, posicao-1);
    insere_direita(aux, novo);

    l->qtde++;
    return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco);

int lista_tamanho(Lista* l);
bool lista_vazia(Lista* l);
bool lista_toString(Lista* l, char* str);