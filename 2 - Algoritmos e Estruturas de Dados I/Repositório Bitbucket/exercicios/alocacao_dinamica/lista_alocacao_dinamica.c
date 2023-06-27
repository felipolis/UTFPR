#include<stdio.h>
#include<string.h>
#include<stdbool.h>



//Exercicio 01
void inverte_string(char* str);
//Exercicio 02
int qtde_vogais1(char* str);
void qtde_vogais2(char* str, int* saida);
//Exercicio 03
char* copia_string(char* str);
//Exercicio 04
int* cria_vetor1(int tam, int valor);
bool cria_vetor2(int tam, int valor, int** saida);
//Exercicio 05
int* clone1(int tam, int valor);
bool clone2(int tam, int valor, int** saida);
//Exercicio 06
int* aleatorio1(int tam);
bool aleatorio2(int tam, int** saida);
//Exercicio 07
int dobra_tamanho(int** v, int tam);

/***********************************************
* FUNCOES AUXILIARES
************************************************/
void imprimir_vetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i<tam-1) printf(",");
    }
    printf("]");
}

void toString_vetor(int* v, int tam, char* saida){
    saida[0] = '\0';
    strcat(saida, "[");

    char elemento[20];
    for (int i=0; i < tam; i++){
        sprintf(elemento, "%d", v[i]);
        strcat(saida, elemento);
        if(i<tam-1) strcat(saida, ",");
    }
    strcat(saida, "]");
}

/***********************************************
* IMPLEMENTACAO
************************************************/

