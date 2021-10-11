#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------------FUNÇÃO DE ORDENAMETO--------------------------------------------

void change(int* v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int partion(int *v, int p, int r){
    int x;
    int i, j;

    x = v[r];
    i = p - 1;

    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            change(v, i, j);
        }
    }

    change(v, i+1, r);
    return i + 1;
}

void quickSort(int* v, int e, int d){
    int q;
    if(e < d){
        q = partion(v, e, d);
        quickSort(v, e, q-1);
        quickSort(v, q+1, d);
    }
}

//---------------------------------------OUTRAS FUNÇÕES--------------------------------------------------


int* random_vector(int n, int max, int seed){
    srand(seed);
    int* vetor = (int*) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        vetor[i] = rand() % max;
    }
    return vetor;
}

void print_vector(int* v, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d  ", v[i]);
    }
    printf("\n\n");
}


//---------------------------------------FUNÇÃO PRINCIPAL------------------------------------------------
int main(){

    int n = 50000;
    int max = 100*n;
    int seed = 42;
    int* v = random_vector(n, max, seed);
    print_vector(v, n);

    //algoritmo
    clock_t start = clock();
    quickSort(v, 0, n-1);
    clock_t end = clock();
    double tempo = (double)(end - start)/CLOCKS_PER_SEC;


    print_vector(v, n);
    printf("Tempo do algoritmo: %f\n", tempo);

    return 0;
}