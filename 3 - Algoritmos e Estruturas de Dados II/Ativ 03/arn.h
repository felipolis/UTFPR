#ifndef _ARN
#define _ARN

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**************************************
* DADOS
**************************************/
typedef struct arn ARN;

/**************************************
* PROTÓTIPOS
**************************************/

ARN* ARN_Criar(int chave, int valor);
void ARN_Inserir(ARN** arvore, int chave, int valor);
void ARN_Imprimir(ARN* arvore, int nivel, char lado);
//void ABB_Remover(ABB** arvore, int dado);
void ARN_Destruir(ARN* arvore);
int ARN_Sort(int* v, int n);
int ARN_altura(ARN* arvore);




#endif