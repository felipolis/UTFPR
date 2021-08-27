/* Gasto de Combustivel
Joaozinho quer calcular e mostrar a quantidade de litros de combustível gastos em uma viagem, ao utilizar um automóvel que faz 12 KM/L. Para isso, ele gostaria que você o auxiliasse através de um simples programa. Para efetuar o cálculo, deve-se fornecer o tempo gasto na viagem (em horas) e a velocidade média durante a mesma (em km/h). Assim, pode-se obter distância percorrida e, em seguida, calcular quantos litros seriam necessários. Mostre o valor com 3 casas decimais após o ponto.

Entrada
O arquivo de entrada contém dois inteiros. O primeiro é o tempo gasto na viagem (em horas) e o segundo é a velocidade média durante a mesma (em km/h).

Saída
Imprima a quantidade de litros necessária para realizar a viagem, com três dígitos após o ponto decimal.

Exemplo
Veja alguns exemplos de casos de teste para validar sua solução. */

#include <stdio.h>

float calcula_litros(float t, float v, float c){
    return (v * t)/c;
}

int main(){

    int tempo, velocidade;
    int const consumo = 12;
    float litros;

    //ENTRADA

    scanf("%d", &tempo);
    scanf("%d", &velocidade);

    //PROCESSAMENTO

    litros = calcula_litros(tempo, velocidade, consumo);

    //SAIDA

    printf("%.3f", litros);

    return 0;
}