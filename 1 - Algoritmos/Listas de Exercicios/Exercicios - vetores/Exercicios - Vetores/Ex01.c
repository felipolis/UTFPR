#include <stdio.h>

int main(){

    int A[10], i, B[10], fat, l;

    for(i = 0; i < 10; i++){

        printf("Digite um numero inteiro: ");
        scanf("%d", &A[i]);

    }

    printf("Vetor A = [%d %d %d %d %d %d %d %d %d %d] \n\n", A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8], A[9]);


    for(i = 0; i < 10; i++){

        fat = 1;

        for(l = 1; l <= A[i]; l++){
            fat = fat * l;
        }

        B[i] = fat;

    }

    printf("Vetor B = [%d %d %d %d %d %d %d %d %d %d] \n\n", B[0], B[1], B[2], B[3], B[4], B[5], B[6], B[7], B[8], B[9]);




    return 0;
}
