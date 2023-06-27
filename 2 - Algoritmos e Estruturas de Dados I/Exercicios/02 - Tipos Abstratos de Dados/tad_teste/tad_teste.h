#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

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