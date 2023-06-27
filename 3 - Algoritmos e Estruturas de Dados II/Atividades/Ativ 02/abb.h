#ifndef _AB
#define _AB

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**************************************
* DADOS
**************************************/
typedef struct abb ABB;

/**************************************
* PROTÓTIPOS
**************************************/

ABB* ABB_Criar(int dado);
void ABB_Inserir(ABB** arvore, int dado);
ABB* ABB_Buscar(ABB* arvore, int dado);
void ABB_Imprimir(ABB* arvore, int nivel, char lado);
void ABB_Remover(ABB** arvore, int dado);
void ABB_Destruir(ABB* arvore);




#endif