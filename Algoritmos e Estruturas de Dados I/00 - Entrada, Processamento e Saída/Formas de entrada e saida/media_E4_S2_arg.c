#include <stdio.h>

float calculo_media(float a, float b, float c){
    return (a+b+c)/3;
}

int main(){

    freopen("entrada.in", "r", stdin);
    freopen("saida.out", "w", stdout);

    //DECLARAÇÃO DE VARIAVEIS
    float n1, n2, n3, media;

    //ENTRADA
    scanf("%f %f %f", &n1, &n2, &n3);

    //PROCESSAMENTO
    media = calculo_media(n1, n2, n3);

    //SAIDA
    printf("%.2f\n", media);

    return 0;
}