#include <stdio.h>
#include <stdlib.h>

float calculo_media(float a, float b, float c){
    return (a+b+c)/3;
}

int main(int argc, char const *argv[]){

    //DECLARAÇÃO DE VARIAVEIS
    float n1, n2, n3, media;

    //ENTRADA
    n1 = atof(argv[1]);
    n2 = atof(argv[2]);
    n3 = atof(argv[3]);

    //PROCESSAMENTO
    media = calculo_media(n1, n2, n3);

    //SAIDA
    printf("%.2f\n", media);

    return 0;
}