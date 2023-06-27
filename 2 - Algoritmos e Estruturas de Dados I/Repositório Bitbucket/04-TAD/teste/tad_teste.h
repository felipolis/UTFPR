#ifndef _TAD_TESTE_H_
#define _TAD_TESTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************
*   DADOS
*******************************************************************/
typedef struct teste Teste;

/*******************************************************************
*   OPERACOES
*******************************************************************/
Teste* teste_criar(char* descricao);
void teste_verificar(Teste* t, int condicao, char *mensagem);
void teste_relatorio(Teste* t);
void teste_desalocar(Teste** t);



#endif