#include <stdio.h>

int main(){
    int a, b;
    
    // ENTRADA
    FILE *arq_in = fopen("entrada.in","r");
    fscanf(arq_in, "%d %d", &a, &b);
    fclose(arq_in);
    
    // PROCESSAMENTO
    int soma = a + b;

    // SAÍDA
    printf("%d\n", soma);

    return 0;
}