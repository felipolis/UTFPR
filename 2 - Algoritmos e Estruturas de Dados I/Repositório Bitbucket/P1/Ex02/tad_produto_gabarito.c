#include "tad_produto.h"

struct produto{
    int codigo;
    char descricao[50];
    double ultimos_precos[4]; // armazena no máximo os últimos 4 preços praticados
    int qtd_precos;           // quantidade de preços armazenados no vetor ultimos_precos
};




/********************************************
 * OPERAÇÕES
********************************************/
Produto* produto_criar(int codigo, char* descricao, double preco){
    Produto* p = (Produto*) malloc(sizeof(Produto));
    p->codigo = codigo;
    strcpy(p->descricao, descricao);
    p->ultimos_precos[0] = preco;
    p->qtd_precos = 1;
    return p;
}

void produto_destruir(Produto** endProduto){
    Produto* p = *endProduto;
    free(p);
    *endProduto = NULL;
}

int produto_codigo(Produto* p){
    return (p == NULL ? -1 : p->codigo);
}

bool produto_descricao(Produto* p, char* saida){
    if(p == NULL) return false;

    strcpy(saida, p->descricao);
    return true;
}

double produto_preco(Produto* p){
    return (p == NULL ? -1 : p->ultimos_precos[p->qtd_precos-1]);
}

double produto_media_preco(Produto* p){
    if(p == NULL) return -1;

    double soma = 0;
    for (int i=0; i < p->qtd_precos; i++){
        soma += p->ultimos_precos[i];
    }
    return soma / p->qtd_precos;
}

bool produto_altera_preco(Produto* p, double preco){
    if(p == NULL) return false;

    if(p->qtd_precos < 4){ // 4 é o tamanho máximo definido por padrão
        p->ultimos_precos[p->qtd_precos++] = preco;
    }else{
        for (int i=0; i < p->qtd_precos-1; i++){
            p->ultimos_precos[i] = p->ultimos_precos[i+1];
        }
        p->ultimos_precos[p->qtd_precos-1] = preco;
    }
    return true;
}