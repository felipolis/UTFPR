#include <stdio.h>

//Funcao de verificacao

int verif(int *vet, int tam, int n){

    int i, j, aux, soma = 0;

    for(i = 0; i < tam; i++){

        if(vet[i] == n){

            soma++;
            aux = i;
            break;

        }

    }

    if(soma == 1){

        return aux;

    }else{
        return -1;
    }


}

//Funcao Main

int main(){

    //Declaracao de variaveis

    int vetor[10], i, x;

    //Recebendo o Numero de verificação

    printf("Digite um numero inteiro para criterio de verificacao: ");
    scanf("%d", &x);

    //Recebendo os valores do vetor

    for(i = 0; i < 10; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &vetor[i]);

    }
    printf("\n\n");

    //Imprimindo o vetor recebido do usuario

    printf("Vetor Recebido do usuario: ");
    for(i = 0; i <10; i++){

        printf("%d\t", vetor[i]);

    }
    printf("\n\n");

    //Chamando a Funcao

    printf("%d", verif(vetor, 10, x));
    printf("\n\n");












    return 0;
}