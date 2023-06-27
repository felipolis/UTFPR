#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



typedef struct no{
    int dado;
    struct no* prox;
}No;

void imprimir_encadeamento(No* aux){
    while(aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
}

int main(){

    int v[3];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    // Criando o espaço para os elementos
    No* p1 = (No*) malloc(sizeof(No));
    No* p2 = (No*) malloc(sizeof(No));
    No* p3 = (No*) malloc(sizeof(No));

    // Copiar os elementos
    (*p1).dado = 1;
    p2->dado = 2;
    p3->dado = 3;

    // Definindo o relacionamento entre os elementos
    p1->prox = p2;
    p2->prox = p3;
    p3->prox = NULL;

    p2 = NULL;
    p3 = NULL;


    for (int i=0; i < 3; i++){
        printf("%d\n",v[i]);
    }



    printf("%d\n",p1->dado);
    printf("%d\n",p1->prox->dado);
    // printf("%d\n",   (*(*p1).prox).dado   );
    printf("%d\n",p1->prox->prox->dado);
    // printf("%d\n",   (*(*(*p1).prox).prox).dado   );

    printf("\n");

    imprimir_encadeamento(p1);




    return 0;
}