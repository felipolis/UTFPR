#include <stdio.h>

int main(){

    float preco, lucro, maiorlucro, melhorpreco;
    int ingressos, melhoringressos;

    for(preco = 5; preco >= 1; preco -= 0.50){

        ingressos = 120 + (5-preco)*52;
        lucro = ingressos*preco-200;
        if (lucro > maiorlucro){
            maiorlucro = lucro;
            melhorpreco = preco;
            melhoringressos = ingressos;

            printf("Lucro: %.2f \nPreco Do Ingresso: %.2f \nIngressos Vendidos: %d \n\n", maiorlucro, melhorpreco, melhoringressos);
        }

    }


    return 0;
}
