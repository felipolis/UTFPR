#include <stdio.h>

int main() {

float salarioAntes;
float percentual;
float aumento;
float salarioDepois;


printf("Qual e seu salario atual? ");
scanf("%f", &salarioAntes);

if(salarioAntes<= 280){
    percentual = 20;
} else if(salarioAntes>280 && salarioAntes<=700){
    percentual = 15;
} else if(salarioAntes>700 && salarioAntes<=1500){
    percentual = 10;
} else{
    percentual = 5;
}

printf("Salario Antes do reajuste: R$ %.2f \n", salarioAntes);
printf("Percentual: %.0f %% \n", percentual);

percentual = percentual/100.00;
aumento = percentual * salarioAntes;
salarioDepois = salarioAntes + aumento;

printf("Aumento: R$ %.2f \n", aumento);
printf("Novo Salario: R$ %.2f \n", salarioDepois);

return 0;

}
