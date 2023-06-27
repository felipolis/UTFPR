#include "tad_estoque.h"

#define TAM 100

struct estoque{
    char descricao[50];
    Produto* vetor[TAM];
    int qtde;
};


Estoque* estoque_criar(char* descricao){
    Estoque* e = (Estoque*) malloc(sizeof(Estoque));
    strcpy(e->descricao, descricao);
    e->qtde = 0;
    return e;
}
void estoque_destruir(Estoque** endEstoque){
    free(*endEstoque);
    *endEstoque = NULL;
}

bool estoque_anexar(Estoque* e, Produto* p){
    if(e->qtde == TAM) return false;

    e->vetor[e->qtde++] = p;
    return true;   
}


int estoque_remover_elemento(Estoque* e, char* descricao){

    for (int i=0; i < e->qtde; i++){
        char desc_produto[100];
        produto_descricao(e->vetor[i], desc_produto);

        if (strcmp(desc_produto, descricao) == 0){
            for (int j=i; j < e->qtde-1; j++){
                e->vetor[j] = e->vetor[j+1];
            }
            e->qtde--;
            return i;
        }
    }
    return -1;
}

void estoque_imprimir(Estoque* e){

    printf("[");
    for (int i=0; i < e->qtde; i++){
        Produto* p = e->vetor[i];
        char desc[100];
        produto_descricao(p, desc);
        printf("(%d,%s,%.2f)", produto_codigo(p), desc, produto_preco(p));
        
        if (i < e->qtde-1) printf(",");
    }
    printf("]");

}