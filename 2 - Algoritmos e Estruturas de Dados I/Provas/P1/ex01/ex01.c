#include "tad_vetor.h"

/***********************************************
* PROVA
************************************************/

Vetor* vet_concatena(Vetor* v1, Vetor* v2){
    int tam1 = v1->qtd;
    int tam2 = v2->qtd;
    int tam3 = tam1 + tam2;

    //Criando Novo Vetor
    Vetor* v3 = vet_criar(tam3);

    //Concatenando os vetores
    for(int i = 0; i < tam3; i++){
        if(i < tam1){
            vet_anexar(v3, v1->vet[i]);
        } else{
            vet_anexar(v3, v2->vet[i - tam1]);
        }
    }

    return v3;
}

Vetor* vet_intercala(Vetor* v1, Vetor* v2){
    int tam1 = v1->qtd;
    int tam2 = v2->qtd;
    int tam3 = tam1 + tam2;
    int j = 0;                                  //aux que vai varrer o vet1
    int k = 0;                                  //aux que vai varrer o vet2

    //Criando Novo Vetor
    Vetor* v3 = vet_criar(tam3);

    //Intercalando os vetores
    for(int i = 0; i < tam3; i++){
        if(j >= tam1){                          //Se o aux extrapolar o tamanho do vet1
            vet_anexar(v3, v2->vet[k]);             //Preencher o resto de vet3 com vet2
            k++;
        } else if(k >= tam2){                   //Se o aux extrapolar o tamanho do vet2
            vet_anexar(v3, v1->vet[j]);             //Preencher o resto de vet3 com vet1
            j++;
        } else if(v1->vet[j] < v2->vet[k]){     //Sendo j < tam1 && o elemento de vet1 < vet2
            vet_anexar(v3, v1->vet[j]);             //Colocar o elemento do vet1 em vet3
            j++;
        } else{                                 //Sendo k < tam2 && o elemento de vet2 < vet1
            vet_anexar(v3, v2->vet[k]);             //Colocar o elemento do vet2 em vet3
            k++;
        }
    }

    return v3;
}