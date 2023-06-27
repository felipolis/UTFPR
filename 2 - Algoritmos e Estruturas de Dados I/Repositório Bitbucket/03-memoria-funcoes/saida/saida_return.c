#include<stdio.h>

int soma(int a, int b){
    int s = a + b;
    return s;
}


int main(){
    // Entrada
    int n1 = 10;
    int n2 = 20;

    // Processamento
    int total = soma(n1, n2);

    // Saída
    printf("%d\n", total);
    return 0;
}