#include "tad_estoque.h"
#include "tad_produto.h"


int main(){
    
    Estoque* e = estoque_criar("estoque");
    Produto* p1 = produto_criar(1, "Pera", 1.0);
    Produto* p2 = produto_criar(2, "Banana", 2.0);
    Produto* p3 = produto_criar(3, "Laranja", 3.0);
    Produto* p4 = produto_criar(4, "Kiwi", 3.0);
    Produto* p5 = produto_criar(5, "Goiaba", 3.0);

    estoque_anexar(e, p1);
    estoque_anexar(e, p2);
    estoque_anexar(e, p3);
    estoque_anexar(e, p4);
    estoque_anexar(e, p5);

    estoque_imprimir(e);
    printf("\n");

    estoque_remover_elemento(e, "Pera");
    estoque_remover_elemento(e, "Goiaba");
    estoque_remover_elemento(e, "Laranja");

    estoque_imprimir(e);

    
    return 0;
}