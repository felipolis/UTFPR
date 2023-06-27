#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TELEFONES 100000
#define TAM_TELEFONE 201

void troca(char** telefones, int i, int j){
    char* aux;
    aux = telefones[i];
    telefones[i] = telefones[j];
    telefones[j] = aux;
}

int partition(char** telefones, int p, int r){
    char* x = telefones[r];
    int i = p-1;
    int j;
    for(j = p; j<r; j++){
        if(strcmp(telefones[j], x) <= 0){
            i++;
            troca(telefones, i, j);
        }
    }
    troca(telefones, i+1, r);
    return i+1;
}

void quicksort_r(char** telefones, int e, int d){
    int q;
    if(e < d){
        q = partition(telefones, e, d);
        quicksort_r(telefones, e, q-1);
        quicksort_r(telefones, q+1, d);
    }
}

void quicksort(char** telefones, int n){
    quicksort_r(telefones, 0, n-1);
}

void print_telefones(char** telefones, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%s\n", telefones[i]);
}

int tam_maior_prefixo_comum(char* ta, char* tb, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(ta[i] != tb[i])
            return i;
    }
    return tam;
}

int economizados(char** telefones, int n){
    int econ = 0;
    int tam_telefone = strlen(telefones[0]);
    int i;

    for(i = 0; i < n-1; i++){
        //printf("*%s* *%s*\n", telefones[i], telefones[i+1]);
        econ += tam_maior_prefixo_comum(telefones[i], telefones[i+1], tam_telefone);  
    }

    return econ;
}

int main(int argc, char** argv){

    int n;
    int i;
    char** telefones;

    telefones = malloc(sizeof(char*) * MAX_TELEFONES);
    for(i = 0; i < MAX_TELEFONES; i++)
        telefones[i] = malloc(sizeof(char) * TAM_TELEFONE);
        
    /*
        O erro do código estava aqui! As entradas no sistema de submissão do URI tinham um \n no final. Como sobrava esse \n, feof(stdin) dava falso, portanto rodava mais uma vez para um caso inexistente..
        
        Mudei a condição para verificar se scanf retorna um número negativo. Isto quer dizer que o scanf não conseguiu transformar a entrada em um inteiro (o \n que sobrou).. Daí quando isso acontece basta terminar a execução.
    
     */
    while(scanf("%d", &n) > 0){
        //printf("%d\n\n", n);

        for(i = 0; i < n; i++){
            scanf("%s", telefones[i]);
            //printf("%s\n", telefones[i]);
        }

        //printf("\n");

        quicksort(telefones, n);

        //print_telefones(telefones, n);

        printf("%d\n", economizados(telefones, n));
    }
    
    for(i = 0; i < MAX_TELEFONES; i++)
        free(telefones[i]);
    free(telefones);

    return 0;


}
