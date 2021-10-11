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

void print_vector(int* v, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d  ", v[i]);
    }
    printf("\n\n");
}


//---------------------------------------FUNÇÃO PRINCIPAL------------------------------------------------
int main(){

    int* v = (int*) calloc(5, sizeof(int));
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;

    print_vector(v, 5);

    //inicio
    clock_t start = clock();
    quickSort(v, 0, 4);
    clock_t end = clock();
    //fim


    double tempo = (double)(end - start)/CLOCKS_PER_SEC;
    print_vector(v, 5);
    printf("Tempo do algoritmo: %f\n", tempo);

    return 0;
}