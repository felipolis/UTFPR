
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*******************************************************************
*   DADOS
*******************************************************************/
typedef struct data Data;


/*******************************************************************
*   OPERACOES
*******************************************************************/
Data* data_criar(int dia, int mes, int ano);
void data_desalocar(Data** enderecoData);
Data* data_clone(Data* d);
bool data_alterar(Data* d, int dia, int mes, int ano);
bool data_string(Data* d, char* str);

