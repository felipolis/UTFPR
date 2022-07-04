#include <stdio.h>

int main(){

    int vendas = 15;
    int i;
    float vista = 0, prazo = 0, total = 0;
    char tipo;

    for(i = 0; i < vendas; i++){

        float valor;

        printf("Digite o tipo do pagamento (P - prazo ; V - Vista):\n");
        scanf(" %c", &tipo);

        printf("\nDigite o valor do pagamento:\n");
        scanf(" %f", &valor);

        total += valor;

        if(tipo == 'p'){

            prazo += valor;

        } else if(tipo == 'v'){

            vista += valor;

        }

    }

    printf("Valor total das vendas a vista: R$ %.2f \n", vista);
    printf("Valor total das vendas a prazo: R$ %.2f \n", prazo);
    printf("Valor total das vendas efetuadas: R$ %.2f \n", total);

    return 0;
}
