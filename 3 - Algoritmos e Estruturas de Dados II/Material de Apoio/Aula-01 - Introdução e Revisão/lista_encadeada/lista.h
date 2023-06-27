#pragma once

#include <stdbool.h>

typedef struct LISTA_NO{
    int dado;
    struct LISTA_NO* prox;
} LISTA_NO;

typedef struct LISTA{
    LISTA_NO* primeiro;
    LISTA_NO* ultimo;
    int tam;
} LISTA;

LISTA* LISTA_Criar();
void LISTA_Inserir(LISTA *L, int dado);
LISTA_NO* LISTA_Buscar(LISTA *L, int dado);
bool LISTA_Vazia(LISTA *L);
int LISTA_Tamanho(LISTA *L);
void LISTA_Imprimir(LISTA *L);
void LISTA_Destruir(LISTA *L);
bool LISTA_Remover(LISTA *L, int dado);
