#include "fila.h"

No* cria_no(TipoElemento elemento){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = elemento;
	novo->prox = NULL;
	return novo;
}

Fila* fila_criar(int ordem){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ordem = ordem;
    f->qtde = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
bool fila_inserir(Fila* f, TipoElemento elemento){

    No* aux = f->inicio;
    No* novo = cria_no(elemento);

    if(f->qtde == 0){ //SE VAZIA

        f->inicio = novo;
        f->fim = novo;

    } else{

        if(f->ordem == 1){ //ASCENDENTE

            if(elemento <= f->inicio->dado){
                novo->prox = f->inicio;
                f->inicio = novo;
            } else if(elemento >= f->fim->dado){
                f->fim->prox = novo;
                f->fim = f->fim->prox;
            } else{
                while(aux != NULL){
                    if(elemento >= aux->dado && elemento <= aux->prox->dado){
                        novo->prox = aux->prox;
                        aux->prox = novo;
                        break;
                    }
                    aux = aux->prox;
                }
            }

        } else{ //DESCENDENTE
            if(elemento >= f->inicio->dado){
                novo->prox = f->inicio;
                f->inicio = novo;
            } else if(elemento <= f->fim->dado){
                f->fim->prox = novo;
                f->fim = f->fim->prox;
            } else{
                while(aux != NULL){
                    if(elemento <= aux->dado && elemento >= aux->prox->dado){
                        novo->prox = aux->prox;
                        aux->prox = novo;
                        break;
                    }
                    aux = aux->prox;
                }
            }
        }

    }

    f->qtde++;
    return true;
}