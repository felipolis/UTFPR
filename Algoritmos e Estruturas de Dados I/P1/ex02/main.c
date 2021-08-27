#include "tad_produto.h"


int main(){
    double media;
    double preco;
    char desc[100];

    printf("Teste\n\n");

    Produto* p = produto_criar(2, "Teclado Mtek", 100.00);
    
    printf("%d\n", produto_codigo(p));

    produto_descricao(p, desc);
    printf("%s\n", desc);

    printf("%.2f\n", produto_preco(p));

    printf("*********\n");

    preco = produto_altera_preco(p, 200.00);
    media = produto_media_preco(p);
    printf("%.2f\n", media);

    preco = produto_altera_preco(p, 300.00);
    media = produto_media_preco(p);
    printf("%.2f\n", media);

    preco = produto_altera_preco(p, 400.00);
    media = produto_media_preco(p);
    printf("%.2f\n", media);

    preco = produto_altera_preco(p, 500.00);
    media = produto_media_preco(p);
    printf("%.2f\n", media);


    return 0;
}