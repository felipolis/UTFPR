#include <iostream>
#include <conio.h>
#include <cstring>
#include "fila.hpp"
#include "lista.hpp"
#include "pilha.hpp"

int main(){

    //UTILIZANDO A LISTA
    ListaEncadeada* l = new ListaEncadeada;
    char aux[100];

    l->inserir(0, 9);
    l->inserir(1, 5);
    l->inserir(2, 3);
    l->inserir(3, 2);
    l->inserir(4, 7);
    l->inserir(5, 0);

    l->toString(aux);
    printf("%s\n", aux);

    l->remover(2);

    l->toString(aux);
    printf("%s\n", aux);

    //UTILIZANDO A FILA
    FilaEncadeada* f = new FilaEncadeada;
    aux[100];

    f->inserir(10);
    f->inserir(6);
    f->inserir(140);
    f->inserir(5);
    f->inserir(3);
    f->inserir(120);
    f->inserir(1);
    f->inserir(4);
    f->inserir(1);

    f->toString(aux);
    printf("%s\n", aux);

    f->remover();

    f->toString(aux);
    printf("%s\n", aux);

    //UTILIZANDO A PILHA
    PilhaEncadeada* p = new PilhaEncadeada;
    aux[100];

    p->empilhar(5);
    p->empilhar(3);
    p->empilhar(2);
    p->empilhar(1);
    p->empilhar(0);

    p->toString(aux);
    printf("%s\n", aux);

    p->desempilhar();

    p->toString(aux);
    printf("%s\n", aux);

    return 0;
}