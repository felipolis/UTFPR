#include <stdio.h>

int main(){

float n1, n2, media;

printf("Digite a primeira nota: ");
scanf("%f", &n1);

printf("Digite a segunda nota: ");
scanf("%f", &n2);

media = (n1 + n2)/2;

if(media>=9 && media<=10){
    printf("A primeira nota: %.1f \n", n1);
    printf("A segunda nota: %.1f \n", n2);
    printf("Voce tirou um A \n");
    printf("Sua media: %.1f \n", media);
    printf("Voce foi aprovado! \n");
} else if(media>=7.5 && media<9){
    printf("A primeira nota: %.1f \n", n1);
    printf("A segunda nota: %.1f \n", n2);
    printf("Voce tirou um B \n");
    printf("Sua media: %.1f \n", media);
    printf("Voce foi aprovado! \n");
} else if(media>=6 && media<7.5){
    printf("A primeira nota: %.1f \n", n1);
    printf("A segunda nota: %.1f \n", n2);
    printf("Voce tirou um C \n");
    printf("Sua media: %.1f \n", media);
    printf("Voce foi aprovado! \n");
} else if(media>=4 && media<6){
    printf("A primeira nota: %.1f \n", n1);
    printf("A segunda nota: %.1f \n", n2);
    printf("Voce tirou um D \n");
    printf("Sua media: %.1f \n", media);
    printf("Voce foi reprovado! \n");
} else if(media>=0 && media<4){
    printf("A primeira nota: %.1f \n", n1);
    printf("A segunda nota: %.1f \n", n2);
    printf("Voce tirou um E \n");
    printf("Sua media: %.1f \n", media);
    printf("Voce foi reprovado! \n");
}


return 0;
}
