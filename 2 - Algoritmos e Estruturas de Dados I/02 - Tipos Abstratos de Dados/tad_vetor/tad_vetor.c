#include "tad_vetor.h"

/***********************************************
* Especificação dos dados
************************************************/
struct vetor{
    int* vet;
    int tamanho;
    int pos;
};



/********************************************
 * Funções auxiliares
 *******************************************/
int tem_espaco(Vetor* v){
    if(v->tamanho - v->pos == 0){
        return 0;
    }
    return 1;
}

int* realocar(Vetor* v){
    int* novoVet = (int*) calloc(2*(v->tamanho) ,sizeof(int));

    int velhoTam = v->tamanho;
    int novoTam = 2*(v->tamanho);
    v->tamanho = novoTam;

    for(int i = 0; i < velhoTam; i++){
        novoVet[i] = v->vet[i];
    }

    return novoVet;
}


/********************************************
 * IMPLEMENTAÇÃO
 *******************************************/

// 1. Criar um novo vetor
/**
 * Cria e inicializa a struct Vetor.
 * RETORNO: endereço da struct Vetor criada e inicializada na memória HEAP
 */
Vetor* vet_criar(int tam){
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->vet = (int*) calloc(tam, sizeof(int));
    v->tamanho = tam;
    v->pos = 0;

    return v;
}

// 2. Inserir um elemento no final da sequência
/**
 * Insere o elemento na última posição do vetor. Caso não haja espaço disponível
 * para a inserção, você deve realocar o vetor, dobrando seu espaço disponível
 * Parâmetro v: Ponteiro para a struct Vetor em que o elemento será inserido.
 * Parâmetro elemento: Elemento a ser inserido.
 * RETORNO: true se a inserção foi realizada com sucesso e false caso contrário
 */
bool vet_anexar(Vetor* v, int elemento){
    if(v == NULL) return false;

    //Verificar se ha espaço no vetor
    if(!tem_espaco(v)){
        v->vet = realocar(v);
    }

    //Adicionando o elemento ao vetor
    v->vet[v->pos] = elemento;
    (v->pos)++;


    return true;
}

// 3. Inserir um elemento em qualquer posição da sequência
/**
 * Insere um elemento em uma determinada posição. Ao inserir um elemento na
 * posição, a função deve deslocar todos os elementos a sua direita. Caso não
 * haja espaço disponível para a inserção, você deve realocar o vetor,
 * dobrando seu espaço disponível
 * Parâmetro v: Ponteiro para a struct Vetor em que o elemento será inserido.
 * Parâmetro elemento: Elemento a ser inserido.
 * Parâmetro posicao: Posição em que o elemento deve ser inserido.
 * RETORNO: true se a inserção foi realizada com sucesso e false caso contrário
 */
bool vet_inserir(Vetor* v, int elemento, int posicao){
    if(v == NULL) return false;
    if(posicao < 0) return false;
    if(posicao > (v->pos)) return false;

    //Verificar se ha espaço no vetor
    if(!tem_espaco(v)){
        v->vet = realocar(v);
    }

    //deslocando valores
    int tam = v->pos;
    for(int i = v->pos; i > posicao; i--){
        v->vet[i] = v->vet[i - 1];
    }
    v->vet[posicao] = elemento;
    (v->pos)++;

    return true;
}

// 4. Substituir um elemento em uma determinada posição
/**
 * Substitui o valor de uma determinada posição do Vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro posicao: Posição a ser alterada.
 * Parâmetro novoElemento: elemento a ser atribuido na posição.
 * RETORNO: true se a alteração foi realizada com sucesso e false caso contrário
 */
bool vet_substituir(Vetor* v, int posicao, int novoElemento){
    if(v == NULL) return false;
    if(posicao < 0) return false;
    if(posicao > (v->pos)-1) return false;

    //Substituindo o valor
    v->vet[posicao] = novoElemento;

    return true;
}

// 5. Remover um elemento de uma determinada posição
/**
 * USANDO A ESTRATÉGIA DO SCANF
 * Remove o elemento de uma determinada posição do vetor .
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro posicao: posição a ser removida.
 * Parâmetro endereco: endereço a ser utilizado para a copiar o valor do elemento removido.
 * RETORNO: true se a inserção foi realizada com sucesso e false caso contrário
 */
bool vet_removerPosicao(Vetor* v, int posicao, int* endereco){
    if(v == NULL) return false;
    if(posicao < 0) return false;
    if(posicao > (v->pos)-1) return false;

    int tam = v->pos;
    int aux;
    int valor = v->vet[posicao];

    //Removendo o elemento da posição
    v->vet[posicao] = -999;
    for(int i = posicao; i < tam - 1; i++){
        aux = v->vet[i];
        v->vet[i] = v->vet[i + 1];
        v->vet[i + 1] = aux;
    }

    (v->pos)--;

    *endereco = valor;
    return true;
}

// 6. Remover um elemento de acordo com o seu valor. Caso haja valores repetidos remover apenas a primeira ocorrência.
/**
 * Remove um determinado elemento do vetor .
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro elemento: elemento a ser removido.
 * RETORNO: posição do elemento removido e -1 caso contrário
 */
int vet_removerElemento(Vetor* v, int elemento){
    if(v == NULL) return -1;

    int tam = v->pos;
    int posicao;
    int aux;
    bool achou = false;

    //Encontrar o valor (O valor existe?)
    for(int i = 0; i < tam; i++){
        if(v->vet[i] == elemento){
            posicao = i;
            v->vet[i] = -999;
            achou = true;
            break;
        }
    }

    //Remover o valor (Se ele existe)
    if(achou){
        for(int i = posicao; i < tam - 1; i++){
            aux = v->vet[i];
            v->vet[i] = v->vet[i + 1];
            v->vet[i + 1] = aux;
        }
        (v->pos)--;
        return posicao;

    } else{
        return -1;
    }


}

// 7. Recuperar quantos elementos estão armazenados na sequência.
/**
 * Devolve a quantidade de elementos do vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * RETORNO: quantidade de elementos do vetor
 */
int vet_tamanho(Vetor* v){
    if(v == NULL) return -1;

    return v->pos;
}

// 8. Recuperar qual elemento está armazenado em uma determinada posição
/**
 * USANDO A ESTRATÉGIA DO SCANF
 * Pesquisa o elemento armazenado em uma determinada posição do Vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro posicao: posicao a ser encontrada.
 * Parâmetro saida: Endereço de memória onde a função deve armazenar o elemento encontrado.
 * RETORNO: Se a posição for válida, realiza a cópia no endereço recebido por parâmetro SAIDA e devolve true.
 *          Caso contrário, devolve false
 */
bool vet_elemento(Vetor* v, int posicao, int* saida){
    if(v == NULL) return false;
    if(posicao < 0) return false;
    if(posicao > (v->pos)-1) return false;
    
    *saida = v->vet[posicao];
    return true;
}

// 9. Recuperar a posição em que um determinado elemento está armazenado. Caso haja valores repetidos, recuperar a primeira ocorrência.
/**
 * Pesquisa a posição de um determinado elemento no Vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro elemento: elemento a ser procurado.
 * RETORNO: Se encontrado, devolve a posição do elemento no vetor; caso contrário devolve -1
 */
int vet_posicao(Vetor* v, int elemento){
    if(v == NULL) return -1;

    int tam = v->pos;
    int posicao;
    bool achou = false;

    //Encontrar o elemento (Ele existe?)
    for(int i = 0; i <tam; i++){
        if(v->vet[i] == elemento){
            achou = true;
            posicao = i;
            break;
        }
    }

    //Retorno
    if(achou){
        return posicao;
    } else{
        return -1;
    }
}

// 10. Imprimir a sequência
/**
 * Imprimir os elementos do vetor
 * Parâmetro v: Ponteiro para a struct Vetor.
 */
void vet_imprimir(Vetor* v){
    printf("[");
    for(int i = 0; i < v->pos; i++){
        printf("%d", v->vet[i]);
        if(i < v->pos -1) printf(",");
    }
    printf("]\n");
}

// 11. Desalocar
/**
 * Destruir/Desalocar/liberar o vetor na memória HEAP
 * Parâmetro v: Ponteiro para a struct Vetor.
 */
void vet_desalocar(Vetor** v){
    free((*v)->vet);
    free(*v);
    *v = NULL;
}

// 12. Devolve o vetor na forma de String
/**
 * Escreve no endereço recebido por parâmetro uma versão string do vetor
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro endereco: endereço da região de memória onde a função deverá copiar os caracteres.
 * RETORNO: true se a cópia foi realizada com sucesso e false caso contrário
 */

bool vet_toString(Vetor* v, char* enderecoString){
    if(v == NULL) return false;

    int tam = v->pos;
    char string[100];

    enderecoString[0] = '\0';
    strcat(enderecoString, "[");
    for (int i=0; i < tam; i++){
        sprintf(string, "%d", v->vet[i]);
        strcat(enderecoString, string);
        if(i<tam-1) strcat(enderecoString, ",");
    }
    strcat(enderecoString, "]");

    return true;
}

