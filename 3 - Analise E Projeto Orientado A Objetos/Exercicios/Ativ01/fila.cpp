#include <iostream>
#include <conio.h>
#include <cstring>

//  CRIAÇÃO DA CLASSE PILHA

typedef int TipoElemento;

class Fila{
    private:
        struct No{
            TipoElemento dado;
            struct No* prox = NULL;
        };
        int qtde = 0;
        No* inicio = NULL;
        No* fim = NULL;

    public:
        void inserir(TipoElemento elemento);
        void remover();
        int quantidade();
        void toString(char* str);
};


//IMPLEMENTAÇÃO DOS METODOS

void Fila::inserir(TipoElemento elemento){
    No* novo = new No;
	novo->dado = elemento;
	novo->prox = NULL;

    if(qtde == 0){
        inicio = novo;
        fim = novo;
    } else{
        fim->prox = novo;
        fim = novo;
    }
    
    qtde++;
}

void Fila::remover(){
    if(qtde == 1){
        free(inicio);
        inicio = NULL;
        fim = NULL;
    } else{
        No* aux_memoria = inicio;
        inicio = inicio->prox;
        free(aux_memoria);
    }

    qtde--;
}

int Fila::quantidade(){
    return qtde;
}

void Fila::toString(char* str){
    No* aux_memoria = inicio;

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

    Fila* f = new Fila;
    char aux[100];

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

    return 0;
}