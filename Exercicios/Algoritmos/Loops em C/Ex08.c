#include <stdio.h>

int main(){

    int n, fat;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    for(fat = 1 ; n > 1 ; n -= 1){

        fat = fat * n;

    }

    printf("Calculo do Fatorial: %d", fat);


    return 0;
}
