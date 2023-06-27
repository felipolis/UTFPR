#include <iostream>
#include <conio.h>
#include <cstring>

//  CRIAÇÃO DA CLASSE PILHA

typedef int TipoElemento;

class Pilha{
    protected:
        struct No{
            TipoElemento dado;
            struct No* prox = NULL;
        }; 
};

class PilhaEncadeada : Pilha{
    private:
        int qtde = 0;
        No* topo = NULL;
    public:
        void empilhar(TipoElemento elemento);
        void desempilhar();
        int quantidade();
        void toString(char* str);
};

//IMPLEMENTAÇÃO DOS METODOS

void PilhaEncadeada::empilhar(TipoElemento elemento){
    No* novo = new No;
    novo->dado = elemento;
    novo->prox = NULL;

	novo->prox = topo;
	topo = novo;
	qtde++;
}

void PilhaEncadeada::desempilhar(){
    No* aux_memoria = topo;

	topo = topo->prox;
	qtde--;

	delete aux_memoria;
}

int PilhaEncadeada::quantidade(){
    return qtde;
}

void PilhaEncadeada::toString(char* str){
    No* aux_memoria = topo;

	str[0] = '\0';
    strcat(str, "[");
    
    while(aux_memoria != NULL){
        char elemento[200];
        sprintf(elemento, "%d", aux_memoria->dado);
        strcat(str, elemento);
        if(aux_memoria->prox != NULL) strcat(str, ",");
		aux_memoria = aux_memoria->prox;
    }
    strcat(str, "]");
}