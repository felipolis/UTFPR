#include "tad_produto.h"

struct produto{
    int codigo;
    char descricao[50];
    double ultimos_precos[4]; // armazena no máximo os últimos 4 preços praticados
    int qtd_precos;           // quantidade de preços armazenados no vetor ultimos_precos
};

//*************************************************************************************************************
Produto* produto_criar(int codigo, char* descricao, double preco){
    //Alocando o produto
    Produto* p = (Produto*) malloc(sizeof(Produto));

    //Definindo as variaveis
    p->codigo = codigo;                         //Definindo o codigo
    strcpy(p->descricao, descricao);            //Copiando a string descricao para dentro da struct
    p->ultimos_precos[0] = preco;               //Adicionando o preço inicial à posicao 0 do vetor
    p->qtd_precos = 1;                          //Definindo a quantidade de preços inicial do produto

    return p;                                   //Retorna o endereço de memoria da struct na HEAP
}

//*************************************************************************************************************
void produto_destruir(Produto** endProduto){
    free(*endProduto);                          //Desaloca o endereço da struct na HEAP
    *endProduto = NULL;                         //Esvazia o ponteiro da main.c             
}


//*************************************************************************************************************
int produto_codigo(Produto* p){
    if(p == NULL) return -1;                    //Validação

    return p->codigo;                           //Retorna o valor do codigo do produto
}


//*************************************************************************************************************
bool produto_descricao(Produto* p, char* saida){
    if(p == NULL) return false;                 //Validação

    strcpy(saida, p->descricao);                //retorna o valor descrição para uma variavel da main.c

    return true;                                //retorna que a função foi bem sucedida
}


//*************************************************************************************************************
double produto_preco(Produto* p){
    if(p == NULL) return false;                         //Validação

    return p->ultimos_precos[p->qtd_precos-1];          //Retorna o ultimo preço do produto
}


//*************************************************************************************************************
double produto_media_preco(Produto* p){
    if(p == NULL) return -1;                                            //Validação

    int quant_precos = p->qtd_precos;
    double media = 0;

    for(int i = 0; i < quant_precos; i++){                              //Loop para calcular media
        media = media + (p->ultimos_precos[i])/quant_precos;
    }

    return media;                                                       //Retorna o valor da media
}


//*************************************************************************************************************
bool produto_altera_preco(Produto* p, double preco){
    if(p == NULL) return false;                                         //Validação

    if(p->qtd_precos < 4){                                              //Se voce esta add o num max de preços

        p->ultimos_precos[p->qtd_precos] = preco;                           //adicione
        p->qtd_precos++;                                                    //incremente

    } else{                                                             //Se você esta add o (4+n)º preço
        
        for(int i = 0; i < p->qtd_precos - 1; i++){                         //Loop para add esse novo preço

            p->ultimos_precos[i] = p->ultimos_precos[i + 1];                //remova o preço mais antigo
            
        }

        p->ultimos_precos[p->qtd_precos - 1] = preco;                       //add o preço mais novo

    }

    return true;                                                            //Retorna se deu certo
}
