#include "lista.h"


/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *inicio;
	No *fim;
	int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* cria_no(TipoElemento elemento){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = elemento;
	novo->ant = NULL;
    novo->prox = NULL;
	return novo;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->qtde = 0;
    l->fim = NULL;
    l->inicio = NULL;
    return l;
}
/*************************************/
void lista_destruir(Lista** endereco){
    Lista* l = *endereco;

    No* aux_memoria = l->inicio;
    while(aux_memoria != NULL){
        l->inicio = l->inicio->prox;
        free(aux_memoria);
        aux_memoria = l->inicio;
    }

    free(*endereco);
    *endereco = NULL;
}
/*************************************/
bool lista_anexar(Lista* l, TipoElemento elemento){
    if(l == NULL) return false;

    No* novo = cria_no(elemento);

    if(l->qtde == 0){   //Se a lista estiver vazia
        l->inicio = novo;
        l->fim = novo;
    } else{     //Se ja tiver algum elemento na lista
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }

    l->qtde++;
    return true;
}
/*************************************/
bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(l == NULL) return false;
    if(posicao > l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    No* novo = cria_no(elemento);

    if(l->qtde == 0){          //(a) inserção na lista está vazia

        l->inicio = novo;
        l->fim = novo;
        l->qtde++;

    } else{
        if(posicao == 0){                       //(b) inserção na primeira posição

            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
            l->qtde++;

        } else if(posicao == l->qtde){       //(c) inserção na última posição

            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
            l->qtde++;

        } else{                                 //(d) inserção no meio

            No* aux = l->inicio;
            for(int i = 0; i < l->qtde; i++){
                if(i == posicao){

                    novo->ant = aux->ant;
                    novo->prox = aux;
                    novo->ant->prox = novo;
                    novo->prox->ant = novo;
                    l->qtde++;
                    break;

                }
                aux = aux->prox;
            }
            
        }
    }

    return true;
}

/*************************************/

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(l == NULL) return false;
    if(posicao >= l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    TipoElemento elemento;

    if(l->qtde == 1){

        elemento = l->inicio->dado;
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
        l->qtde--;

    } else{

        if(posicao == 0){

            elemento = l->inicio->dado;
            No* aux = l->inicio;
            l->inicio = l->inicio->prox;
            l->inicio->ant = NULL;
            free(aux);
            l->qtde--;

        } else if(posicao == l->qtde - 1){

            elemento = l->fim->dado;
            No* aux = l->fim;
            l->fim = l->fim->ant;
            l->fim->prox = NULL;
            free(aux);
            l->qtde--;

        } else{

            No* aux = l->inicio;
            for(int i = 0; i < l->qtde; i++){
                if(i == posicao){
                    elemento = aux->dado;
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    l->qtde--;
                    break;
                }
                aux = aux->prox;
            }

        }
    }

    *endereco = elemento;
    return true;
}
/*************************************/
int lista_removerElemento(Lista* l, TipoElemento elemento){
    if(l == NULL) return false;
    
    No* aux = l->inicio;
    bool achou = false;

    for(int i = 0; i < l->qtde; i++){

        if(aux->dado == elemento){

            if(l->qtde == 1){

                free(l->inicio);
                l->inicio = NULL;
                l->fim = NULL;

            }else{
                if(i == 0){

                    l->inicio = l->inicio->prox;
                    l->inicio->ant = NULL;
                    free(aux);

                } else if(i == l->qtde - 1){

                    l->fim = l->fim->ant;
                    l->fim->prox = NULL;
                    free(aux);

                } else{

                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux); 

                }
            }
            achou = true;
            l->qtde--;
            break;

        }else{
            aux = aux->prox;
        }

    }

    if(achou){
        return true;
    } else{
        return false;
    }

}

/*************************************/
bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if(l == NULL) return false;
    if(posicao >= l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    No* aux = l->inicio;

    for(int i = 0; i < l->qtde; i++){

        if(i == posicao){
            aux->dado = novoElemento;
            break;
        }

        aux = aux->prox;
    }

    return true;
}
/*************************************/
int lista_posicao(Lista* l, TipoElemento elemento){
    if(l == NULL) return -1;
    int indice;
    bool achou = false;

    No* aux = l->inicio;
    for(int i = 0; i < l->qtde; i++){

        if(aux->dado == elemento){
            indice = i;
            achou = true;
            break;
        }

        aux = aux->prox;
    }

    if(achou){
        return indice;
    } else{
        return -1;
    }

}
/*************************************/
bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(l == NULL) return false;
    if(posicao >= l->qtde) return false;
    if(posicao < 0){
        posicao = posicao + l->qtde;
        if(posicao < 0) return false;
    }

    TipoElemento elemento;

    No* aux = l->inicio;
    for(int i = 0; i < l->qtde; i++){

        if(i == posicao){
            *endereco = aux->dado;
            break;
        }

        aux = aux->prox;
    }

    return true;
}
/*************************************/
int lista_tamanho(Lista* l){
    if(l == NULL) return -1;
    return l->qtde;
}
/*************************************/
bool lista_vazia(Lista* l){
    if(l == NULL) return false;

    return (l->qtde == 0 ? true : false);
}
/*************************************/
bool lista_toString(Lista* l, char* str){
    if(l == NULL) return false;

    No* aux = l->inicio;

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