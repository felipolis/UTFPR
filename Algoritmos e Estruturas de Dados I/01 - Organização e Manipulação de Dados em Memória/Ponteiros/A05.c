#include <stdio.h>
#include <string.h>

int main(){

    typedef struct produto{
        int codigo;
        char descricao[12];
        float preco;
    } Produto;

    Produto prod = {1, "Teclado", 98.50};
    Produto* p = &prod;
    int* pi = &prod.codigo;
    char* pc = prod.descricao;
    float* pf = &prod.preco;

    printf("----------------\n");

    printf("p = %d\n", p);
    printf("&p = %d\n", &p);
    printf("&prod = %d\n", &prod);
    printf("prod.codigo = %d\n", prod.codigo);
    printf("&prod.codigo = %d\n", &prod.codigo);
    printf("p->codigo = %d\n", p->codigo);
    printf("&p->codigo = %d\n", &p->codigo);
    printf("prod.descricao = %s\n", prod.descricao);
    printf("&prod.descricao = %d\n", &prod.descricao);
    printf("p->descricao = %s\n", p->descricao);
    printf("&p->descricao = %d\n", &p->descricao);
    printf("prod.preco = %f\n", prod.preco);
    printf("&prod.preco = %d\n", &prod.preco);
    printf("p->preco = %f\n", p->preco);
    printf("&p->preco = %d\n", &p->preco);

    printf("----------------\n");

    prod.codigo = 1;
    printf("%d\n", prod.codigo);

    *pi = 2;
    printf("%d\n", prod.codigo);

    (*p).codigo = 3;
    printf("%d\n", prod.codigo);

    p->codigo = 4;
    printf("%d\n", prod.codigo);

    printf("----------------\n");

    strcpy(prod.descricao, "Mouse");
    printf("%s\n", prod.descricao);

    strcpy(pc, "Teclado");
    printf("%s\n", prod.descricao);

    strcpy((*p).descricao, "Headset");
    printf("%s\n", prod.descricao);

    strcpy(p->descricao, "Monitor");
    printf("%s\n", prod.descricao);

    printf("----------------\n");

    prod.preco = 5.00;
    printf("%.2f\n", prod.preco);

    *pf = 10.50;
    printf("%.2f\n", prod.preco);

    (*p).preco = 15.99;
    printf("%.2f\n", prod.preco);

    p->preco = 28.50;
    printf("%.2f\n", prod.preco);

    return 0;
}