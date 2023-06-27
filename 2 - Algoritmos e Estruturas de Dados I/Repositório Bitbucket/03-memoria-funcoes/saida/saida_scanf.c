#include<stdio.h>

void soma(int a, int b, int* saida){
    int s = a + b;
    *saida = s;
}


int main(){
    // Entrada
    int n1 = 10;
    int n2 = 20;

    // Processamento
    int total;
    soma(n1, n2, &total);

    // Saída
    printf("%d\n", total);
    
    return 0;
}