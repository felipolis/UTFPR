#include <stdio.h>

int main(){

int idade;

printf("Digite a idade do nadador para saber sua categoria: ");
scanf("%d", &idade);

switch (idade){

    case 5 ... 7:
        printf("Infantil");
        break;

    case 8 ... 10:
        printf("Juvenil");
        break;

    case 11 ... 15:
        printf("Adolescente");
        break;

    case 16 ... 30:
        printf("Adulto");
        break;

    default:
        printf("Senior");
        break;

}






return 0;

}
