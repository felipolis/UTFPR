#include <stdio.h>

int main() {

float custoFabrica;
float custoConsumidor;
float pDistribuidor;
float pImpostos;

printf("Digite o valor do custo de fabrica: ");
scanf("%f", &custoFabrica);

if(custoFabrica<=12000){
    pDistribuidor = 0.5;
    pImpostos = 0;
} else if(custoFabrica>12000 && custoFabrica<=25000){
    pDistribuidor = 0,1;
    pImpostos = 0,15;
} else{
    pDistribuidor = 0,15;
    pImpostos = 0,2;
}

custoConsumidor = custoFabrica + (pDistribuidor * custoFabrica) + (pImpostos * custoFabrica);
printf("Custo ao Consumidor: %.2f", custoConsumidor);

return 0;

}
