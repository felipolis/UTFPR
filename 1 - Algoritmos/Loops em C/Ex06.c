#include <stdio.h>

int main(){

    int idade, i;
    float peso, altura;
    char olhos, cabelo;

    int quantidadepeso = 0, quantpesoaltura = 0, totalidade = 0, quantruivas = 0, quantolhosazuis = 0;
    float media1, media2;



    for(i = 1 ; i <= 2 ; i++){

        printf("Digite a idade da pessoa:\n");
        scanf("%d", &idade);


        printf("Digite a altura da pessoa:\n");
        scanf("%f", &altura);


        printf("Digite o peso da pessoa:\n");
        scanf("%f", &peso);

        printf("Digite a cor dos olhos da pessoa (A - Azul, P - Preto, V - Verde, C - Castanho):\n");
        scanf(" %c", &olhos);

        printf("Digite a cor dos cabelos da pessoa (P - preto, L - Louro, R - Ruivo):\n");
        scanf(" %c", &cabelo);



        if(idade > 50 && peso < 60){

            quantidadepeso++;

        }
        if(altura < 1.5){

            quantpesoaltura++;
            totalidade += idade;
            media1 = totalidade/quantpesoaltura;

        }
        if (olhos == 'a'){

            quantolhosazuis++;
            media2 = (quantolhosazuis/20)*100;

        }
        if(cabelo == 'r' && olhos != 'a'){

            quantruivas++;

        }

    }

        printf("quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 quilos: %d \n", quantidadepeso);

        printf("média das idades das pessoas com altura inferior a 1,5 metro: %.2f \n", media1);

        printf("percentagem de pessoas com olhos azuis entre todas as pessoas analisadas: %.2f \n", media2);

        printf("quantidade de pessoas ruivas e que nao possuem olhos azuis: %d \n", quantruivas);

    return 0;
}
