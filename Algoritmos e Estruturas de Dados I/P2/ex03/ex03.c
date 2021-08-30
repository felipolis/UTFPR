#include "lista_incidencia.h"

No* cria_no(int elemento){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = elemento;
	novo->prox = NULL;
	return novo;
}

Lista* lista_criar(int nos){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->nos = nos;
    l->vetor = (No**) calloc(nos, sizeof(No*));
    for(int i = 0; i < nos; i++){
        l->vetor[i] = NULL;
    }
    return l;
}

bool lista_inserirCaminho(Lista* l, int a, int b){
    if(l == NULL) return false;

    No* novo1 = cria_no(b);
    novo1->prox = l->vetor[a];
    l->vetor[a] = novo1;

    No* novo2 = cria_no(a);
    novo2->prox = l->vetor[b];
    l->vetor[b] = novo2;

    return true;
}

bool lista_removerCaminho(Lista* l, int a, int b){
    if(l == NULL) return false;
    if(!lista_temCaminho(l, a, b)) return false;

    No* aux = NULL;
    No* aux_memoria = NULL;

    //Varrer na pos a
    aux = l->vetor[a];
    if(aux->dado == b){
        l->vetor[a] = l->vetor[a]->prox;
        free(aux);
        aux = NULL;
    } else{
        while(aux->prox != NULL){
            if(aux->prox->dado == b){
                aux_memoria = aux->prox;
                aux->prox = aux->prox->prox;
                free(aux_memoria);
                aux_memoria = NULL;
                break;
            }
            aux = aux->prox;
        }
    }

    //Varrer na pos b
    aux = l->vetor[b];
    if(aux->dado == a){
        l->vetor[b] = l->vetor[b]->prox;
        free(aux);
        aux = NULL;
    } else{
        while(aux->prox != NULL){
            if(aux->prox->dado == a){
                aux_memoria = aux->prox;
                aux->prox = aux->prox->prox;
                free(aux_memoria);
                aux_memoria = NULL;
                break;
            }
            aux = aux->prox;
        }
    }


    return true;
}


bool lista_temCaminho(Lista* l, int a, int b){
    if(l == NULL) return false;
    if(a > l->nos || b > l->nos) return false;
    bool achou_em_a = false;
    bool achou_em_b = false;

    No* aux = NULL;

    //Varrer na pos a
    aux = l->vetor[a];
    while(aux != NULL){
        if(aux->dado == b){
            achou_em_a = true;
            break;
        }
        aux = aux->prox;
    }

    //Varrer na pos b
    aux = l->vetor[b];
    while(aux != NULL){
        if(aux->dado == a){
            achou_em_b = true;
            break;
        }
        aux = aux->prox;
    }

    return (achou_em_a && achou_em_b ? true : false);
}


void lista_destruir(Lista** enderecoLista){
    Lista* l = *enderecoLista;
    No* aux = NULL;
    for(int i = 0; i < l->nos; i++){
        aux = l->vetor[i];
        while(aux != NULL){
            l->vetor[i] = aux->prox;
            free(aux);
            aux = l->vetor[i];
        }
    }
    free(l->vetor);
    free(*enderecoLista);
    *enderecoLista = NULL;
}



void lista_toString(Lista* l, char* saida){
    saida[0] = '\0';
    char string[100];

    for(int i=0; i < l->nos; i++){
        sprintf(string, "[%d] ", i);
        strcat(saida, string);

        for(int j=0; j < l->nos; j++){
            if (lista_temCaminho(l, i, j)){
                sprintf(string, "%d ", j);
                strcat(saida, string);
            }
        }
        strcat(saida, "\n");        
    }
}