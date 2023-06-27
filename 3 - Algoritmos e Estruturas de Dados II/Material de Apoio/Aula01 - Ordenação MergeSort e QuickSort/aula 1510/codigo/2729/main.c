#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXITENS 1000

typedef struct ListaCompras{
    char **itens;
    int n;
} ListaCompras;

ListaCompras* LC_Criar(char *listona){
    ListaCompras* lc = malloc(sizeof(ListaCompras));
    int n = 0;

    lc->itens = malloc(sizeof(char*) * MAXITENS);

    char* item = strtok(listona, " \n");

    while(item != NULL){
        lc->itens[n] = malloc(sizeof(char) * (strlen(item)+1));
        strcpy(lc->itens[n], item);
        item = strtok(NULL, " \n");
        n++;
    }

    lc->n = n;
    return lc;
}

void LC_Imprimir(ListaCompras *lc){
    for(int i = 0; i < lc->n; i++){
        printf("%s ", lc->itens[i]);
    }
    printf("\n");    
}

int cmp_str(const void* a, const void* b)
{
    return strcmp(*((char**) a), *((char**) b));
}

void LC_Ordenar(ListaCompras* lc){
    qsort(lc->itens, lc->n, sizeof(char*), cmp_str);
}

void LC_ImprimirUnicos(ListaCompras* lc){
    LC_Ordenar(lc);

    printf("%s ", lc->itens[0]);
    char *ult_impresso = lc->itens[0];
    int i;

    for(i = 1; i < lc->n; i++){
        if(strcmp(ult_impresso, lc->itens[i]) != 0){
            printf("%s ", lc->itens[i]);
            ult_impresso = lc->itens[i];
        }
    }

    printf("\n");
}

int main(void){

    char listona[] = "carne laranja suco picles laranja picles";

    ListaCompras *lc = LC_Criar(listona);

    LC_Imprimir(lc);

    LC_ImprimirUnicos(lc);
    

    return 0;

}