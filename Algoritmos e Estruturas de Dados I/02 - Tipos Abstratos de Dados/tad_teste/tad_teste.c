#include "tad_teste.h"

/*******************************************************************
*   ESPECIFICACAO DA STRUCT
*******************************************************************/

struct teste{
    char descricao[100];
    int quant_total;
    int quant_acertos;
    int quant_erros;
};

/*******************************************************************
*   FUNCOES AUXILIARES
*******************************************************************/

void linhas(){
    printf("----------------------------------------------------\n");
}

/*******************************************************************
*   IMPLEMENTACAO
*******************************************************************/

Teste* teste_criar(char* descricao){
    Teste* t = (Teste*) malloc(sizeof(Teste));
    strcpy(t->descricao, descricao);
    t->quant_total = 0;
    t->quant_acertos = 0;
    t->quant_erros = 0;
    return t;
}

void teste_verificar(Teste* t, int condicao, char *mensagem){
    t->quant_total++;
    if(condicao){
        t->quant_acertos++;
        printf("[OK]: %s\n", mensagem);
    } else{
        t->quant_erros++;
        printf("Erro: %s\n", mensagem);
    }
}

void teste_relatorio(Teste* t){
    printf("\n");
    linhas();
    printf("%s\n", t->descricao);
    linhas();
    printf("Total    = %d\nPassaram = %d\nFalharam = %d\n", t->quant_total, t->quant_acertos, t->quant_erros);
}

void teste_desalocar(Teste** t){
    free(*t);
    *t = NULL;
}