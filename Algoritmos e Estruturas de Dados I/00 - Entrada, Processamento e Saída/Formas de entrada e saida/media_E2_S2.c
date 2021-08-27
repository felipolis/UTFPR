#include <stdio.h>

float calculo_media(float a, float b, float c){
    return (a+b+c)/3;
}

int main(){

    //DECLARAÇÃO DE VARIAVEIS
    float n1, n2, n3, media;

    //ENTRADA
    n1 = 6.5;
    n2 = 7.7;
    n3 = 5.3;

    //PROCESSAMENTO
    media = calculo_media(n1, n2, n3);

    //SAIDA
    FILE *arq_out = fopen("saida.out", "w");
    fprintf(arq_out, "%.2f\n", media);
    fclose(arq_out);

    return 0;
}