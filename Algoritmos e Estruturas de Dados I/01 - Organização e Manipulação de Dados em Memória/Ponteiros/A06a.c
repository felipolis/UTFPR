#include <stdio.h>
#include <string.h>

int main(){

    typedef struct produto{
        int codigo;
        char descricao[12];
        float preco;
    } Produto;

    Produto prodA = {1, "Teclado", 98.50};
    Produto prodB = {2, "Mouse", 65.00};
    Produto prodC= {3, "Webcam", 130.00};

    Produto vet[4];
    vet[0] = prodA;
    vet[1] = prodB;
    vet[2] = prodC;

    printf("&vet[0] = %d\n\n", &vet[0]);

    printf("&vet[0].codigo = %d\n", &vet[0].codigo);
    printf("&vet[0].descricao = %d\n", &vet[0].descricao);
    printf("&vet[0].preco = %d\n", &vet[0].preco);
    printf("vet[0].codigo = %d\n", vet[0].codigo);
    printf("vet[0].descricao = %s\n", vet[0].descricao);
    printf("vet[0].preco = %.2f\n\n", vet[0].preco);

    printf("&vet[1].codigo = %d\n", &vet[1].codigo);
    printf("&vet[1].descricao = %d\n", &vet[1].descricao);
    printf("&vet[1].preco = %d\n", &vet[1].preco);
    printf("vet[1].codigo = %d\n", vet[1].codigo);
    printf("vet[1].descricao = %s\n", vet[1].descricao);
    printf("vet[1].preco = %.2f\n\n", vet[1].preco);

    printf("&vet[2].codigo = %d\n", &vet[2].codigo);
    printf("&vet[2].descricao = %d\n", &vet[2].descricao);
    printf("&vet[2].preco = %d\n", &vet[2].preco);
    printf("vet[2].codigo = %d\n", vet[2].codigo);
    printf("vet[2].descricao = %s\n", vet[2].descricao);
    printf("vet[2].preco = %.2f\n\n", vet[2].preco);

    /*
    printf("&vet[3].codigo = %d\n", &vet[3].codigo);
    printf("&vet[3].descricao = %d\n", &vet[3].descricao);
    printf("&vet[3].preco = %d\n", &vet[3].preco);
    printf("vet[3].codigo = %d\n", vet[3].codigo);
    printf("vet[3].descricao = %s\n", vet[3].descricao);
    printf("vet[3].preco = %.2f\n\n", vet[3].preco); */

    return 0;
}