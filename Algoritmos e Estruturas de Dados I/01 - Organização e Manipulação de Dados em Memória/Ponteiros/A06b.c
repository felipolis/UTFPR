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
    Produto prodD= {4, "Headset", 150.00};
    Produto* vet[4];

    vet[0] = &prodA;
    vet[1] = &prodB;
    vet[2] = &prodC;
    vet[3] = &prodD;

    printf("&vet[0] = %d\n", &vet[0]);
    printf("&vet[1] = %d\n", &vet[1]);
    printf("&vet[2] = %d\n", &vet[2]);
    printf("&vet[3] = %d\n", &vet[3]);
    printf("vet[0] = %d\n", vet[0]);
    printf("vet[1] = %d\n", vet[1]);
    printf("vet[2] = %d\n", vet[2]);
    printf("vet[3] = %d\n\n", vet[3]);

    printf("&prodA.codigo = %d\n", &prodA.codigo);
    printf("&prodA.descricao = %d\n", &prodA.descricao);
    printf("&prodA.preco = %d\n", &prodA.preco);
    printf("prodA.codigo = %d\n", prodA.codigo);
    printf("prodA.descricao = %s\n", prodA.descricao);
    printf("prodA.preco = %f\n\n", prodA.preco);

    printf("&prodB.codigo = %d\n", &prodB.codigo);
    printf("&prodB.descricao = %d\n", &prodB.descricao);
    printf("&prodB.preco = %d\n", &prodB.preco);
    printf("prodB.codigo = %d\n", prodB.codigo);
    printf("prodB.descricao = %s\n", prodB.descricao);
    printf("prodB.preco = %f\n\n", prodB.preco);

    printf("&prodC.codigo = %d\n", &prodC.codigo);
    printf("&prodC.descricao = %d\n", &prodC.descricao);
    printf("&prodC.preco = %d\n\n", &prodC.preco);
    printf("prodC.codigo = %d\n", prodC.codigo);
    printf("prodC.descricao = %s\n", prodC.descricao);
    printf("prodC.preco = %f\n\n", prodC.preco);
    
    printf("----------------\n");

    (*vet[2]).codigo = 100;
    printf("prodC.codigo = %d\n", prodC.codigo);

    printf("----------------\n");

    strcpy((*vet[1]).descricao, "Mouse sem fio");
    printf("prodB.descricao = %s\n", prodB.descricao);

    printf("----------------\n");

    printf("&prodD.codigo = %d\n", &prodD.codigo);
    printf("&prodD.descricao = %d\n", &prodD.descricao);
    printf("&prodD.preco = %d\n\n", &prodD.preco);
    printf("prodD.codigo = %d\n", prodD.codigo);
    printf("prodD.descricao = %s\n", prodD.descricao);
    printf("prodD.preco = %f\n\n", prodD.preco);

    return 0;
}