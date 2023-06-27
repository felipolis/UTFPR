#include "tad_data.h"

/*******************************************************************
*   ESPECIFICACAO DA STRUCT
*******************************************************************/
struct data{
    int dia;
    int mes;
    int ano;
};

/*******************************************************************
*   IMPLEMENTACAO
*******************************************************************/

Data* data_criar(int dia, int mes, int ano){
    Data* d = (Data*) calloc(1,sizeof(Data));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

void data_desalocar(Data** enderecoData){
    // Data* d = *enderecoData;
    // free(d);
    free(*enderecoData);
    *enderecoData = NULL;
}

Data* data_clone(Data* d){
    Data* novo = data_criar(d->dia, d->mes, d->ano);
    return novo;
}

bool data_alterar(Data* d, int dia, int mes, int ano){

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return true;
}

bool data_string(Data* d, char* str){
    sprintf(str, "%02d/%02d/%d", d->dia, d->mes, d->ano);
    return 1;
}