#include <stdio.h>
#include <stdlib.h>


int somaVetor(int* vetor, int tam){
    int i, soma = 0;;
    for(i=0; i<tam; i++){
        soma += vetor[i];
    }
    return soma;
}



int main(void) {
  
    // Alocando o vetor
    int vet1[4];

    int* vet2;
    vet2 =(int*)calloc(4, sizeof(int));

    // Manipulando os dados
    int* p1 = vet1;
    int* p2 = vet2;

    vet1[0] = 10;
    *(vet1 + 1) = 20;
    p1[2] = 30;
    *(p1+3) = 40;

    vet2[0] = 50;
    *(vet2 + 1) = 60;
    p2[2] = 70;
    *(p2+3) = 80;


    // Passando vetor por parâmetro
    int soma1 = somaVetor(vet1, 4);
    int soma2 = somaVetor(vet2, 4);


    // Liberando memória
    free(vet2);
    vet2 = p2 = NULL;



}