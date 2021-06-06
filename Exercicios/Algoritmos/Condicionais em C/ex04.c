#include <stdio.h>

int main() {

int n;

printf("Digite um numero de 1-7: ");
scanf("%d", &n);

switch (n) {

    case 1:
        printf("Domingo");
        break;

    case 2:
        printf("Segunda");
        break;

    case 3:
        printf("Terca");
        break;

    case 4:
        printf("Quarta");
        break;

    case 5:
        printf("Quinta");
        break;

    case 6:
        printf("Sexta");
        break;

    case 7:
        printf("Sabado");
        break;

    default:
        printf("Valor Invalido");
        break;
}

return 0;

}
