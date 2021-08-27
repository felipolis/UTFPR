#include "fila.h"
#include "string.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct fila {
	TipoElemento* vetor;
	int tam;
	int inicio;
	int fim;
	int qtde;
};

/**************************************
* Funções Auxiliares
**************************************/
void verifica_aumenta(Fila* f){
    if(f->fim == f->inicio){
        TipoElemento* novo_vetor = (TipoElemento*) calloc(f->tam*2, sizeof(TipoElemento));

        int pos_novo = 0;
        int pos_antigo = f->inicio;
        while(true){
            novo_vetor[pos_novo] = f->vetor[pos_antigo];
            pos_antigo = (pos_antigo + 1) % f->tam;
            pos_novo++;
            if(pos_antigo == f->inicio) break;
        }

        f->tam = f->tam*2;
        f->inicio = 0;
        f->fim = f->qtde;

        free(f->vetor);
        f->vetor = novo_vetor;
    }
}
void verifica_diminui(Fila* f){
    int quant = f->qtde;
    int tam = f->tam;
    float taxa_ocupacao = (float)quant/tam;

    if(taxa_ocupacao < 0.25){
        TipoElemento* novo_vetor = (TipoElemento*) calloc(f->tam/2, sizeof(TipoElemento));

        int pos_novo = 0;
        int pos_antigo = f->inicio;
        while(true){
            novo_vetor[pos_novo] = f->vetor[pos_antigo];
            pos_antigo = (pos_antigo + 1) % f->tam;
            pos_novo++;
            if(pos_antigo == f->fim) break;
        }

        f->tam = f->tam / 2;
        f->inicio = 0;
        f->fim = f->qtde;

        free(f->vetor);
        f->vetor = novo_vetor;
    }
}

bool fila_ehValida(Fila* f){
    return (f != NULL? true: false);
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tam = TAM_INICIAL;
    f->qtde = 0;
    f->inicio = f->fim = 0;
}

void fila_destruir(Fila** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->tam;
    f->qtde++;
    verifica_aumenta(f);

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    TipoElemento elemento = f->vetor[f->inicio];
    f->inicio = (f->inicio+1) % f->tam;
    *saida = elemento;
    f->qtde--;
    verifica_diminui(f);

    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->vetor[f->inicio];
    return true;
}

bool fila_vazia(Fila* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

void fila_toString(Fila* f, char* str){
    if (!fila_ehValida(f)) return;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    int i = f->inicio;
    while(i != f->fim){
        sprintf(elemento,"%d", f->vetor[i]);
        strcat(str, elemento);
        if ((i+1)%f->tam != f->fim) strcat(str, ",");
        i = (i+1) % f->tam;
    }
    strcat(str, "]");
    //printf("tamvet = %d\n", f->tam);
}