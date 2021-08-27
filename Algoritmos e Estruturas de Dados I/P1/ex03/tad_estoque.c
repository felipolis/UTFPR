#include "tad_estoque.h"

#define TAM 100

struct estoque{
    char descricao[50];
    Produto* vetor[TAM];
    int qtde;
};

//*************************************************************************************************************
Estoque* estoque_criar(char* descricao){
    Estoque* e = (Estoque*) malloc(sizeof(Estoque));

    strcpy(e->descricao, descricao);
    e->qtde = 0;

    return e;
}

//*************************************************************************************************************
void estoque_destruir(Estoque** endEstoque){
    free(*endEstoque);
    *endEstoque = NULL;
}

//*************************************************************************************************************
bool estoque_anexar(Estoque* e, Produto* p){
    if(e == NULL) return false;
    if(p == NULL) return false;

    e->vetor[e->qtde] = p;
    (e->qtde)++;

    return true;
}

//*************************************************************************************************************
int estoque_remover_elemento(Estoque* e, char* descricao){
    if(e == NULL) return -1;

    //printf("%s\n", descricao);

    char desc_para_remover[100];
    strcpy(desc_para_remover, descricao);

    char desc_aux[100];

    int quant_produtos = e->qtde;
    int comparacao;
    int pos;
    bool achou = false;

    for(int i = 0; i < quant_produtos; i++){

        produto_descricao(e->vetor[i], desc_aux);
        comparacao = strcmp(desc_para_remover, desc_aux);

        if(comparacao == 0){
            pos = i;
            achou = true;
            break;
        }

    }

    if(!achou) return -1;

    for(int i = pos; i < quant_produtos-1; i++){

        e->vetor[i] = e->vetor[i+1];

    }

    e->qtde--;

    return pos;
}

//*************************************************************************************************************
void estoque_imprimir(Estoque* e){
    int id;
    double preco;
    char descricao[100];

    printf("[");
    for(int i = 0; i < e->qtde; i++){

        id = produto_codigo(e->vetor[i]);
        preco = produto_preco(e->vetor[i]);
        produto_descricao(e->vetor[i], descricao);

        printf("(%d,%s,%.2f)", id, descricao, preco);
        if(i < e->qtde-1) printf(",");
    }
    printf("]");
}