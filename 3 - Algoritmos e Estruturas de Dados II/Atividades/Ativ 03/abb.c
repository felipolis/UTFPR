#include "abb.h"

/**************************************
 * DADOS
 **************************************/
struct abb{
    struct abb *esq;
    int dado;
    struct abb *dir;
};

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/
ABB *ABB_Buscar(ABB *arvore, int dado){
    if (arvore == NULL) return NULL;
    if (arvore->dado == dado) return arvore;

    if (dado < arvore->dado){
        return ABB_Buscar(arvore->esq, dado);
    }
    else{
        return ABB_Buscar(arvore->dir, dado);
    }
}

ABB *antecessor(ABB **arvore){
    if ((*arvore)->dir != NULL){
        return antecessor(&(*arvore)->dir);
    }
    else{
        ABB *aux = *arvore;
        if ((*arvore)->esq != NULL){
            *arvore = (*arvore)->esq;
        }
        else{
            *arvore = NULL;
            return aux;
        }
    }
}

void verifica_nivel(int nivel){
    for (int i = 1; i <= nivel; i++){
        printf("        ");
    }
}

void ABB_Sort_R(ABB* arvore, int* v, int n, int pos){
    if(arvore == NULL) return;

    pos--;
    ABB_Sort_R(arvore->esq, v, n, pos);
    v[pos] = arvore->dado;
    ABB_Sort_R(arvore->dir, v, n, pos);
}

int maior(int a, int b){
    if(a > b){
        return a;
    } else{
        return b;
    }
}

/**************************************
 * FUNÇÕES PRINCIPAIS
 **************************************/

ABB *ABB_Criar(int dado){
    ABB *arvore = (ABB *)malloc(sizeof(ABB));
    arvore->dado = dado;
    arvore->esq = NULL;
    arvore->dir = NULL;

    return arvore;
}

void ABB_Inserir(ABB **arvore, int dado){
    if (*arvore == NULL){
        *arvore = ABB_Criar(dado);
        return;
    }
    else{
        if (dado < (*arvore)->dado){
            ABB_Inserir(&(*arvore)->esq, dado);
        }
        else{
            ABB_Inserir(&(*arvore)->dir, dado);
        }
    }
}

void ABB_Remover(ABB **arvore, int dado){
    if (*arvore == NULL){
        printf("O numero nao existe na arvore!\n");
        return;
    }
    else{
        if (dado < (*arvore)->dado){
            ABB_Remover(&(*arvore)->esq, dado);
        } else if (dado > (*arvore)->dado){
            ABB_Remover(&(*arvore)->dir, dado);
        } else {
            ABB *aux = *arvore;
            if ((*arvore)->esq == NULL && (*arvore)->dir == NULL){
                free(aux);
                *arvore = NULL;
                aux = NULL;
            } else if ((*arvore)->esq == NULL){
                *arvore = (*arvore)->dir;
                aux->dir = NULL;
                free(aux);
                aux = NULL;
            } else if ((*arvore)->dir == NULL){
                *arvore = (*arvore)->esq;
                aux->esq = NULL;
                free(aux);
                aux = NULL;
            } else { // TEM MAIS DE UM FILHO
                aux = antecessor(&(*arvore)->esq);
                aux->esq = (*arvore)->esq;
                aux->dir = (*arvore)->dir;
                (*arvore)->esq = NULL;
                (*arvore)->dir = NULL;
                free(*arvore);
                *arvore = aux;
                aux = NULL;
            }
        }
    }
}

int ABB_altura(ABB* arvore){
    if(arvore == NULL || (arvore->esq == NULL && arvore->dir == NULL)){
        return 0;
    } else{
        return 1 + maior(ABB_altura(arvore->esq), ABB_altura(arvore->dir));
    }
}

int ABB_Sort(int* v, int n){
    int alt;

    //Crie uma ABB A
    ABB* abb = NULL;

    //Insira todos os elementos de V em A
    for(int i = 0; i < n; i++){
        ABB_Inserir(&abb, v[i]);
    }
    alt = ABB_altura(abb);
    //printf("Altura da arvore: %d\n", alt);
    

    //Faça um percurso em-ordem de A, inserindo os elementos de volta em V
    ABB_Sort_R(abb, v, n, n);

    //Destrua a arvore A
    ABB_Destruir(abb);

    return alt;
}

void ABB_Imprimir(ABB* arvore, int nivel, char lado){
    if (arvore == NULL) return;

    if (nivel == 0 && lado == 'r'){
        printf("(r) %d\n", arvore->dado);
    }
    else if (lado == 'e'){
        verifica_nivel(nivel);
        printf("(e) %d\n", arvore->dado);
    }
    else if (lado == 'd'){
        verifica_nivel(nivel);
        printf("(d) %d\n", arvore->dado);
    }
    nivel++;

    ABB_Imprimir(arvore->esq, nivel, 'e');
    ABB_Imprimir(arvore->dir, nivel, 'd');
}


void ABB_Destruir(ABB* arvore){
    if(arvore == NULL) return;
    ABB_Destruir(arvore->esq);
    ABB_Destruir(arvore->dir);
    free(arvore);
}