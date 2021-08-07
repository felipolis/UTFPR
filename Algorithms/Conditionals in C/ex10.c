#include <stdio.h>

int main() {

char combustivel;
float litros;
float desconto;
float total;

printf("O senhor gostaria de pagar por qual tipo de combustivel? \n");
printf("G - Gasolina \n");
printf("A - Alcool \n");
scanf("%c", &combustivel);

printf("Quantos litros o senhor gostaria de comprar? \n");
scanf("%f", &litros);

if (combustivel == 'a'&& litros>0 && litros <= 40){

    total = (litros * 3.00);
    desconto = (total * 4/100);
    total = total - desconto;
    printf ("Total a pagar: R$ %.2f", total);

} else if (combustivel=='a' && litros>0 && litros > 40){

    total = (litros * 3.00);
    desconto = (total * 6/100);
    total = total - desconto;
    printf ("Total a pagar: R$ %.2f", total, total);

} else if(combustivel == 'a' && litros<=0){

    printf("Quantidade em litros invalida!");

}



if (combustivel == 'g' && litros>0 && litros <= 40){

    total = (litros * 4.50);
    desconto = (total * 3/100);
    total = total - desconto;
    printf ("Total a pagar: R$ %.2f", total, total);

}
else if (combustivel=='g' && litros>0 && litros > 40){

    total = (litros * 4.50);
    desconto = (total * 5/100);
    total = total - desconto;
    printf ("Total a pagar: R$ %.2f", total, total);

} else if(combustivel == 'g' && litros<=0){

    printf("Quantidade em litros invalida!");

}

return 0;

}
