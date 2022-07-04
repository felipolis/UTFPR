#include <iostream>
#include <conio.h>
#include <cstring>

//  CRIAÇÃO DA CLASSE PILHA

typedef int TipoElemento;

class Pilha{
    private:
        struct No{
            TipoElemento dado;
            struct No* prox = NULL;
        };
        int qtde = 0;
        No* topo = NULL;

    public:
        void empilhar(TipoElemento elemento);
        void desempilhar();
        int quantidade();
        void toString(char* str);
};

//IMPLEMENTAÇÃO DOS METODOS

void Pilha::empilhar(TipoElemento elemento){
    No* novo = new No;
    novo->dado = elemento;
    novo->prox = NULL;

	novo->prox = topo;
	topo = novo;
	qtde++;
}

void Pilha::desempilhar(){
    No* aux_memoria = topo;

	topo = topo->prox;
	qtde--;

	delete aux_memoria;
}

int Pilha::quantidade(){
    return qtde;
}

void Pilha::toString(char* str){
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


// FUNÇÃO PRINCIPAL

int main(){

    Pilha* p = new Pilha;
    char aux[100];

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


