#include <stdlib.h>

#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED* HT, int chave){
    return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){
    THED *nova;
    int i;

    nova = malloc(sizeof(THED));
    nova->m = m;
    nova->t = malloc(sizeof(ILIST*) * m);
    for(i = 0; i < m; i++)
        nova->t[i] = ILIST_Criar(alloc_step);

    return nova;
}

void THED_Inserir(THED* HT, int chave, int valor){
    int h;
    h = THED_Hash(HT, chave);
    ILIST_Inserir(HT->t[h], chave, valor);
}

INOH* THED_Buscar(THED* HT, int chave){
    int h, pos;
    h = THED_Hash(HT, chave);
    pos = ILIST_Buscar(HT->t[h], chave);
    return ILIST_Endereco(HT->t[h], pos);
}

void THED_Remover(THED* HT, int chave){
    int h, pos;
    h = THED_Hash(HT, chave);
    pos = ILIST_Buscar(HT->t[h], chave);
    ILIST_Remover(HT->t[h], pos);
}