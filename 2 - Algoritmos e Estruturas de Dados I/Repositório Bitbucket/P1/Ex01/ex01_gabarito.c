#include "tad_vetor.h"

/***********************************************
* PROVA
************************************************/

Vetor* vet_concatena(Vetor* v1, Vetor* v2){
    int tam = vet_tamanho(v1) + vet_tamanho(v2);

    Vetor* v = vet_criar(tam);
    int elemento;
    for (int i=0; i < vet_tamanho(v1); i++){
        vet_anexar(v, v1->vet[i]);
    }    
    for (int i=0; i < vet_tamanho(v2); i++){
        vet_anexar(v, v2->vet[i]);
    }    
    return v;
}

Vetor* vet_intercala(Vetor* v1, Vetor* v2){
    int tam = vet_tamanho(v1) + vet_tamanho(v2);
    Vetor* v3 = vet_criar(tam);
    int i = 0, j = 0;

    while(vet_tamanho(v3) < tam){
        bool temElemento_v1 = i < v1->qtd;
        bool temElemento_v2 = j < v2->qtd;
        
        // Vou inserir o elemento do v1 quando 
        // - Tiver elementos em v1 e ele for o menor, ou quando não existe mais elementos em v2
        if ( (temElemento_v1 && v1->vet[i] <= v2->vet[j]) || (!temElemento_v2) ){
            vet_anexar(v3, v1->vet[i++]);
        }else{
            vet_anexar(v3, v2->vet[j++]);
        }
    }
    return v3;
}


