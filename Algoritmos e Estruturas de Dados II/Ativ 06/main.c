#include <stdio.h>
#include "hashtable_ea.h"

unsigned int random_32bits(){
    unsigned int x;
    x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    return x;
}

int* random_vector(int n, int max, int seed){
    int* v = (int*)malloc(n*sizeof(int));
    int i;
    srand(seed);
    for(i=0; i<n; i++){
        v[i] = random_32bits() % max;
    }
    return v;
}

// ------------------------------------------------------------
#define N 10000
#define MAX 10*N
#define SEED 42

int main(){

    int m = 30000;

    THEA* t = THEA_Criar(m);

    int* elemetos = random_vector(N, MAX, SEED);
    for(int i=0; i<N; i++){
        
        THEA_Inserir(t, elemetos[i], elemetos[i]);

    }

    printf("N: %d\n", t->n);
    printf("Fator de carga: %f\n", (float) t->n/t->m);
    printf("Custo medio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
    printf("Custo medio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
    printf("Maior cluster da tabela: %d\n", THEA_ClusterMaximo(t));

    //THEA_Imprimir(t);

    return 0;
}