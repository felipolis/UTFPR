#include "tad_data.h"

/*******************************************************************
*   ESPECIFICACAO DA STRUCT
*******************************************************************/
struct data{
    char dia[3];
    char mes[3];
    char ano[5];
};

/*******************************************************************
*   OPERACOES
*******************************************************************/
Data* data_criar(int dia, int mes, int ano);
void data_desalocar(Data** enderecoData);
Data* data_clone(Data* d);
bool data_alterar(Data* d, int dia, int mes, int ano);
bool data_string(Data* d, char* str);