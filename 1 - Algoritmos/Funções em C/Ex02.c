#include <stdio.h>

///Funcao media

float media(float n1, float n2, float n3){
    float media;

    media = (float)(n1*3 + n2*4 + n3*3)/10;
    
    return media;
}

///Funcao main

int main(){
    
    ///Declaracao de variaveis

    float x, y, z;

    ///Recebendo os valores das notas

    printf("Digite a primeira nota: ");
    scanf("%f", &x);

    printf("Digite a segunda nota: ");
    scanf("%f", &y);

    printf("Digite a terceira nota: ");
    scanf("%f", &z);

    ///Imprimindo o dobro do valor

    printf("A media das notas eh: %.2f", media(x,y,z));

    return 0;
}


