/* Problema
Joãozinho comprou N produtos iguais e pagou X reais. A atendente devolveu Y reais de troco. Quanto Joãozinho pagou em cada produto?

Escreva um algoritmo para calcular o custo de cada produto

Entrada
O arquivo de entrada contém três inteiros. O primeiro é o valor pago, o segundo é o troco e o terceiro é a quantidade.

Saída
Imprima o custo de cada produto com dois dígitos após o ponto decimal.

Se os valores informados na entrada inviabilizam o processamento, o algoritmo deve apresentar o valor -1.00 como saída.

Exemplo
As informações devem ter a ordem valor troco quantidade */

#include <stdio.h>

float calculo_valor_unitario(float pago, float troco, float qtd){
    if(troco > pago){
        return -1;
    }
    if(qtd == 0){
        return -1;
    }
    return (pago - troco)/qtd;
}

int main(){

    int quant;
    float valor_pago, valor_troco, valor_unitario;

    //ENTRADA

    scanf("%f %f %d", &valor_pago, &valor_troco, &quant);

    //PROCESSAMENTO

    valor_unitario = calculo_valor_unitario(valor_pago, valor_troco, quant);

    //SAIDA

    printf("%.2f", valor_unitario);

    return 0;
}