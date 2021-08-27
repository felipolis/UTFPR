#include <stdio.h>

float calculo_media(float a, float b, float c){
    return (a+b+c)/3;
}

int main(){

    //DECLARAÇÃO DE VARIAVEIS
    float n1, n2, n3, media;

    //ENTRADA
    FILE *arq_in = fopen("entrada.in", "r");
    fscanf(arq_in, "%f %f %f", &n1, &n2, &n3);
    fclose(arq_in);

    //PROCESSAMENTO
    media = calculo_media(n1, n2, n3);

    //SAIDA
    printf("%.2f\n", media);

    return 0;
}