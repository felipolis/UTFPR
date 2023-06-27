#pragma once

typedef enum ExprTreeTipoNo{
    ETTN_CONSTANTE,
    ETTN_OP
} ExprTreeTipoNo;

typedef struct ExprTree{
    struct ExprTree *esq;
    struct ExprTree *dir;
    ExprTreeTipoNo tipo_no;
    int num;  // válido quando tipo_no == ETTN_CONSTANTE
    char op;  // válido quando tipo_no == ETTN_OP
}ExprTree;

ExprTree* ET_CriarNoOp(char op, ExprTree * e, ExprTree *d);
ExprTree* ET_CriarNoConstante(int num);
ExprTree* ET_ConstruirArvExpressao(char *rpn);
int ET_AvaliarExpressao(ExprTree* et);

void ET_GenDOT(ExprTree *A, const char* arq_saida);
void ET_Destruir(ExprTree *A);
