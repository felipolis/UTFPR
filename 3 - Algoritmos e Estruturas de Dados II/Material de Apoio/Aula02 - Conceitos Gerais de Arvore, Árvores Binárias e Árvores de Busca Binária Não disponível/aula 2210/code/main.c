#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shunting_yard.h"
#include "exprtree.h"


int main(int argc, char** argv){

    char* rpn;

    ExprTree* arv_expr;

    char *infixa = (argc == 1) ? "(2+4)/2+1" : argv[1];

    rpn = shunting_yard(infixa);

    arv_expr = ET_ConstruirArvExpressao(rpn);

    ET_GenDOT(arv_expr, "arvore.dot");

    int resultado = ET_AvaliarExpressao(arv_expr);

    printf("%s = %d\n", infixa, resultado);

    return 0;

}
