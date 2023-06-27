#include <stdio.h>
#include <stdlib.h>

void print_vector(int *v, int n){
    int i;
    for(i = 0; i < n-1; i++){
        printf("%d, ", v[i]);
    }    
    printf("%d\n", v[i]);
}

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int *v, int p, int r){
    int x = v[r];
    int j;
    int i = p - 1;
    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i+1], &v[r]);
    return i+1;
}

void quicksort(int *v, int ini, int fim){
    if(ini < fim){
        int q = partition(v, ini, fim);
        quicksort(v, ini, q-1);
        quicksort(v, q+1, fim);
    }
}

int partition_dec(int *v, int p, int r){
    int x = v[r];
    int j;
    int i = p - 1;
    for(j = p; j < r; j++){
        if(v[j] >= x){
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i+1], &v[r]);
    return i+1;
}

void quicksort_dec(int *v, int ini, int fim){
    if(ini < fim){
        int q = partition_dec(v, ini, fim);
        quicksort_dec(v, ini, q-1);
        quicksort_dec(v, q+1, fim);
    }
}

int separar_pares_e_impares(int *v, int n){
    int p = -1;
    int j;
    for(j = 0; j < n; j++){
        if((v[j] % 2) == 0){
            p++;
            troca(&v[p], &v[j]);
        }
    }
    return p+1;
}

void pares_impares_ordenados(int *v, int n){

    int primeiro_impar = separar_pares_e_impares(v, n);

    print_vector(v, n);

    quicksort(v, 0, primeiro_impar-1);

    print_vector(v, n);

    quicksort_dec(v, primeiro_impar, n-1);

    print_vector(v, n);

}

int main(void){
    int *v;
    int n;
    int i;

    scanf("%d", &n);

    printf("%d\n", n);
    
    
    /*
       No final da aula tivemos um segfault... O único "probleminha"
       é que eu havia esquecido de alocar o vetor v!!! haha
       
       Agora está tudo funcionando como deveria.
    */
    v = malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    pares_impares_ordenados(v, n);

    free(v);

    return 0;

}
