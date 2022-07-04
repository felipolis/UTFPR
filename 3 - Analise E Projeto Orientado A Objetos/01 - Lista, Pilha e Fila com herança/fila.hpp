#include <iostream>
#include <conio.h>
#include <cstring>

//  CRIAÇÃO DA CLASSE PILHA

typedef int TipoElemento;

class Fila{
    protected:
        struct No{
            TipoElemento dado;
            struct No* prox = NULL;
        };
};

class FilaEncadeada : public Fila{
    private:
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

void FilaEncadeada::inserir(TipoElemento elemento){
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

void FilaEncadeada::remover(){
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

int FilaEncadeada::quantidade(){
    return qtde;
}

void FilaEncadeada::toString(char* str){
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