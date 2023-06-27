#include <stdio.h>
#include "lista.h"

int main(int argc, char** argv){

    LISTA* L = LISTA_Criar();

    LISTA_Inserir(L, 10);
    LISTA_Inserir(L, 20);
    LISTA_Inserir(L, 30);

    LISTA_Imprimir(L);

    LISTA_Inserir(L, 40);

    LISTA_Imprimir(L);

    return 0;

}
