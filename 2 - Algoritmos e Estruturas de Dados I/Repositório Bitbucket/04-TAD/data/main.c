#include<stdio.h>
#include<stdlib.h>


#include "tad_data.h"

int main(){
    /*******************************************
    * TAD - O que eu preciso?
    ********************************************
    - Criar uma data
    - Desalocar uma data
    - Obter uma versão string da data "06/07/2021"
    - Alterar uma data
    - Duplicar uma data
    ********************************************/

    // Criar uma data
    Data* d1 = data_criar(6,7,2021);

    // Obter uma versão string da data "06/07/2021"
    // char* str = data_string(d1);
    // free(str);

    char str[200];
    data_string(d1, str);


    printf("%s\n", str);  // "06/07/2021"

    // Duplicar uma data
    Data* d2 = data_clone(d1);
    data_string(d2, str);
    printf("%s\n", str);  // "06/07/2021"

    // Alterar uma data
    data_alterar(d2, 10, 12, 2021);
    data_string(d2, str);
    printf("%s\n", str);  // "10/12/2021"

    // Desalocar uma data
    data_desalocar(&d1);
    printf("%d\n", d1 == NULL);  // 1

    data_desalocar(&d2);
    printf("%d\n", d2 == NULL);  // 1

    return 0;

}