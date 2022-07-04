#include <iostream>
#include <conio.h>
#include <cstring>

//  CRIAÇÃO DA CLASSE LISTA

typedef int TipoElemento;

class Lista{
    private:
        struct No{
            TipoElemento dado;
            struct No* ant = NULL;
            struct No* prox = NULL;
        };
        int qtde = 0;
        No* inicio;
        No* fim;

    public:
        void inserir(int pos, TipoElemento elemento);
        void remover(int pos);
        int quantidade();
        void toString(char* str);
};

//IMPLEMENTAÇÃO DOS METODOS

void Lista::inserir(int pos, TipoElemento elemento){
    No* novo = new No;
    novo->dado = elemento;
    novo->ant = NULL;
    novo->prox = NULL;
    
    if(qtde == 0){
        inicio = novo;
        fim = novo;
        qtde++;
    } else{
        if(pos == 0){
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
            qtde++;
        } else if(pos == qtde){
            novo->ant = fim;
            fim->prox = novo;
            fim = novo;
            qtde++;
        } else{
            No* aux = inicio;
            for(int i = 0; i < qtde; i++){
                if(i == pos){

                    novo->ant = aux->ant;
                    novo->prox = aux;
                    novo->ant->prox = novo;
                    novo->prox->ant = novo;
                    qtde++;
                    break;

                }
                aux = aux->prox;
            }
        }
    }
    
}

void Lista::remover(int pos){
    if(qtde == 1){

        delete inicio;
        inicio = NULL;
        fim = NULL;
        qtde--;

    } else{

        if(pos == 0){

            No* aux = inicio;
            inicio = inicio->prox;
            inicio->ant = NULL;
            delete aux;
            qtde--;

        } else if(pos == qtde - 1){

            No* aux = fim;
            fim = fim->ant;
            fim->prox = NULL;
            delete aux;
            qtde--;

        } else{

            No* aux = inicio;
            for(int i = 0; i < qtde; i++){
                if(i == pos){
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    qtde--;
                    break;
                }
                aux = aux->prox;
            }

        }
    }
}

int Lista::quantidade(){
    return qtde;
}

void Lista::toString(char* str){
    No* aux = inicio;

	str[0] = '\0';
    strcat(str, "[");

    while(aux != NULL){
        char elemento[200];
        sprintf(elemento, "%d", aux->dado);
        strcat(str, elemento);
        if(aux->prox != NULL) strcat(str, ",");
		aux = aux->prox;
    }
    strcat(str, "]");
}

// FUNÇÃO PRINCIPAL

int main(){

    Lista* l = new Lista;
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

    return 0;
}


