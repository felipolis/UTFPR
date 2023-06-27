#include<stdio.h>
#include<stdbool.h>
#include "pilha.h"


#define MAX_LIMIT 301



int main(){

    int tam;
    char expressao[MAX_LIMIT];
    scanf("%d\n", &tam);

    for (int i=0; i < tam; i++){
        fgets(expressao, MAX_LIMIT, stdin);
        expressao[strlen(expressao)-1] = '\0';

        printf("%s\n", expressao);
    }

    return 0;
}