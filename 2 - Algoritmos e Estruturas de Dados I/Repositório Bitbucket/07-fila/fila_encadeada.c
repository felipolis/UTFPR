#include "fila.h"
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

/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool fila_ehValida(Fila* f){
    return (f != NULL? true: false);
}

No* novoNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}



/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

void fila_destruir(Fila** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    No* aux;
    while(f->inicio != NULL){
        aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    No* novo = novoNo(elemento);

    if(f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->qtde++;

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    No* aux = f->inicio;
    f->inicio = f->inicio->prox;
    f->qtde--;
    *saida = aux->dado;
    free(aux);

    if(f->inicio == NULL){
        f->fim = NULL;
    }

    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->inicio->dado;
    return true;
}

bool fila_vazia(Fila* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

bool fila_toString(Fila* f, char* str){
    if (!fila_ehValida(f)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    No* aux = f->inicio;

    while(aux != NULL){
        sprintf(elemento,"%d", aux->dado);
        strcat(str, elemento);
        if (aux->prox != NULL) strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}
