#include "arn.h"

/**************************************
 * DADOS
 **************************************/
typedef enum{
    C_VERMELHO,
    C_PRETO
} ARN_COR;

struct arn{
    struct arn* esq;
    struct arn* dir;
    int chave;
    int valor;
    ARN_COR cor;
};

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/

ARN* criar_no(int chave, int valor){
    ARN* novo = (ARN*) malloc(sizeof(ARN));

    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int eh_vermelho(ARN* arvore){
    if(arvore == NULL) return 0;
    return arvore->cor == C_VERMELHO ? 1 : 0;
}

void inverter_cores(ARN* arvore){
    arvore->cor = C_VERMELHO;
    arvore->esq->cor = C_PRETO;
    arvore->dir->cor = C_PRETO;
}

void rot_esq(ARN** arvore){
    ARN* h = *arvore;
    ARN* x = h->dir;

    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *arvore = x;
}

void rot_dir(ARN** arvore){
    ARN* h = *arvore;
    ARN* x = h->esq;

    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *arvore = x;
}

void ARN_Inserir_R(ARN** arvore, int chave, int valor){
    if((*arvore) == NULL){
        *arvore = criar_no(chave, valor);
        return;
    }

    if(chave < (*arvore)->chave){
        ARN_Inserir_R(&(*arvore)->esq, chave, valor);
    }

    if(chave > (*arvore)->chave){
        ARN_Inserir_R(&(*arvore)->dir, chave, valor);
    }

    if(eh_vermelho((*arvore)->dir) && !eh_vermelho((*arvore)->esq)){
        rot_esq(arvore);
    }

    if(eh_vermelho((*arvore)->esq) && eh_vermelho((*arvore)->esq->esq)){
        rot_dir(arvore);
    }

    if(eh_vermelho((*arvore)->esq) && eh_vermelho((*arvore)->dir)){
        inverter_cores(*arvore);
    }
}

void ARN_Sort_R(ARN* arvore, int* v, int n, int pos){
    if(arvore == NULL) return;

    pos--;
    ARN_Sort_R(arvore->esq, v, n, pos);
    v[pos] = arvore->chave;
    ARN_Sort_R(arvore->dir, v, n, pos);
}

int ARN_Sort(int* v, int n){
    int alt;

    //Crie uma ABB A
    ARN* arn = NULL;

    //Insira todos os elementos de V em A
    for(int i = 0; i < n; i++){
        ARN_Inserir(&arn, v[i], 0);
    }
    alt = ARN_altura(arn);

    //Faça um percurso em-ordem de A, inserindo os elementos de volta em V
    ARN_Sort_R(arn, v, n, n);

    //Destrua a arvore A
    ARN_Destruir(arn);

    return alt;

}

int maiorARN(int a, int b){
    if(a > b){
        return a;
    } else{
        return b;
    }
}


/**************************************
 * FUNÇÕES PRINCIPAIS
 **************************************/

ARN* ARN_Criar(int chave, int valor){
    ARN* novo = (ARN*) malloc(sizeof(ARN));

    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_PRETO;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}
void ARN_Inserir(ARN** arvore, int chave, int valor){
    ARN_Inserir_R(arvore, chave, valor);
    (*arvore)->cor = C_PRETO;
}

void ARN_Imprimir(ARN* A, int nivel, char lado){
    for(int i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", lado);
    }
    else{
        printf("(%c) %d [%s]\n", lado, A->chave, A->cor == C_VERMELHO ? "V" : "P");
        ARN_Imprimir(A->esq, nivel+1, 'e');
        ARN_Imprimir(A->dir, nivel+1, 'd');
    }
}

void ARN_Destruir(ARN* arvore){
    if(arvore == NULL) return;
    ARN_Destruir(arvore->esq);
    ARN_Destruir(arvore->dir);
    free(arvore);
}


int ARN_altura(ARN* arvore){
    if(arvore == NULL || (arvore->esq == NULL && arvore->dir == NULL)){
        return 0;
    } else if((arvore->cor == C_VERMELHO)){
        return 0 + maiorARN(ARN_altura(arvore->esq), ARN_altura(arvore->dir));
    } else{
        return 1 + maiorARN(ARN_altura(arvore->esq), ARN_altura(arvore->dir));
    }
}


