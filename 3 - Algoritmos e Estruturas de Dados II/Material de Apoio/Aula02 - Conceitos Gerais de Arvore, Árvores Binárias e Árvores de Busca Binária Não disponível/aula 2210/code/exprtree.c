#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "exprtree.h"
#include "etstack.h"

ExprTree* ET_CriarNoOp(char op, ExprTree * e, ExprTree *d){
    ExprTree* novo;

    novo = malloc(sizeof(ExprTree));
    novo->tipo_no = ETTN_OP;
    novo->op = op;
    novo->esq = e;
    novo->dir = d;
    return novo;
}

ExprTree* ET_CriarNoConstante(int num){
    ExprTree* novo;

    novo = malloc(sizeof(ExprTree));
    novo->tipo_no = ETTN_CONSTANTE;
    novo->num = num;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;    
}

ExprTree* ET_ConstruirArvExpressao(char *rpn){
    ETSTACK* pilha_nos;
    char *p;
    ExprTree *tmp, *op1, *op2, *raiz;

    pilha_nos = ETSTACK_Criar(10);

    p = strtok(rpn, " \n");

    while(p != NULL){

        if(isdigit(*p)){
            tmp = ET_CriarNoConstante(atoi(p));
        }
        else{
            op1 = ETSTACK_Desempilhar(pilha_nos);
            op2 = ETSTACK_Desempilhar(pilha_nos);
            tmp = ET_CriarNoOp(*p, op2, op1);
        }
        ETSTACK_Empilhar(pilha_nos, tmp);

        p = strtok(NULL, " \n");

    }

    raiz = ETSTACK_Desempilhar(pilha_nos);
    ETSTACK_Destruir(pilha_nos);

    return raiz;
}

int ET_AvaliarExpressao(ExprTree* et){
    if(et->tipo_no == ETTN_CONSTANTE){
        return et->num;
    }
    else{
        int e = ET_AvaliarExpressao(et->esq);
        int d = ET_AvaliarExpressao(et->dir);
        switch(et->op){
            case '+':
                return e + d;
            case '-':
                return e - d;
            case '*':
                return e * d;
            case '/':
                return e / d;
        }
    }
}

void ET_Destruir(ExprTree *A){
    if(A == NULL)
        return;
    ET_Destruir(A->esq);
    ET_Destruir(A->dir);
    free(A);
}

static int ET_GenDOT_R(ExprTree *A, FILE* saida, int *id){
    int e, d, me;

    if(A == NULL)
        return 0;

    e = ET_GenDOT_R(A->esq, saida, id);
    d = ET_GenDOT_R(A->dir, saida, id);

    me = (*id)++;

    if(A->tipo_no == ETTN_CONSTANTE)
        fprintf(saida, "%d [label=\"%d\"];\n", me, A->num);
    else
        fprintf(saida, "%d [label=\"%c\"];\n", me, A->op);

    if(e || d){
        if(e)
            fprintf(saida, "%d -> %d;\n", me, e);
        if(d)
            fprintf(saida, "%d -> %d;\n", me, d);
    }

    return me;

}

void ET_GenDOT(ExprTree *A, const char* arq_saida){

    FILE* saida;
    int id = 1;

    saida = fopen(arq_saida, "w");

    fprintf(saida, "digraph G {\n");

    ET_GenDOT_R(A, saida, &id);

    fprintf(saida, "}\n");

    fclose(saida);

}
