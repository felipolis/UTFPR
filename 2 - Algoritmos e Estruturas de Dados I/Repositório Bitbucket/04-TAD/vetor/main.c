
#include "tad_vetor.h"

int main(){

    Vetor* v1 = vet_criar(10);    // []


    vet_anexar(v1, 10);         // [10]
    vet_anexar(v1, 20);         // [10,20]
    vet_anexar(v1, 30);         // [10,20,30]
    vet_imprimir(v1);           //[10,20,30]


    if (vet_inserir(v1, 5, 0)){
        printf("Insercao com sucesso");
    }else{
        printf("posicao invalida");
    }

    vet_inserir(v1, 50, 9) == false;



    int x;
    vet_elemento(v1, 2, &x);





}