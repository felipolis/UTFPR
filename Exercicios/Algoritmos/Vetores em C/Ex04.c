#include <stdio.h>

int main(){

    ///Declaração de variaveis

    int A[5];
    int i;
    int j;
    int result = 0;

    ///Lendo os numeros inteiros no vetor A

    for(i = 0; i < 5; i++){

        do{
            printf("Digite um numero inteiro e positivo: ");
            scanf("%d", &A[i]);
            if(A[i] < 0){
                printf("Digite um numero positivo!\n");
            }
        } while(A[i] < 0);

    }

    ///Imprimindo o vetor A

    printf("Vetor A = [ ");
    for(i = 0; i < 5; i++){

        printf("%d ", A[i]);

    }
    printf("]\n\n");

    ///Numeros primos

    for(i = 0; i < 5; i++){

        for(j = 2; j <= A[i]/2; j++){

            if(A[i] % j == 0){

                result++;
                break;

            }

        }

        if(result == 0){

            printf("%d eh um numero primo, na posicao %d! \n", A[i], i);

        } else {

            printf("%d nao eh um numero primo, na posicao %d! \n", A[i], i);

        }

    }



    return 0;
}
