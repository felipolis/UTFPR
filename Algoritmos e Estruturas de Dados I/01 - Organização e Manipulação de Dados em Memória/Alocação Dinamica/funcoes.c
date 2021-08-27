#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

//Exercicio 01
void inverte_string(char* str);
//Exercicio 02
int qtde_vogais1(char* str);
int qtde_vogais2(char* str, int* saida);
//Exercicio 03
char* copia_string(char* str);
//Exercicio 04
int* cria_vetor1(int tam, int valor);
bool cria_vetor2(int tam, int valor, int** saida);
//Exercicio 05
int* clone1(int *vetor, int tamanho);
bool clone2(int *vetor, int tamanho, int** saida);
//Exercicio 06
int* aleatorio1(int tam);
bool aleatorio2(int tam, int** saida);
//Exercicio 07
int dobra_tamanho(int** v, int tam);
//EXERCICIO 08
int** cria_matriz(int linhas, int colunas, int valor);

/***********************************************
* FUNCOES AUXILIARES
************************************************/
void imprimir_vetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i<tam-1) printf(",");
    }
    printf("]");
}

void toString_vetor(int* v, int tam, char* saida){
    saida[0] = '\0';
    strcat(saida, "[");
    
    char elemento[20];
    for (int i=0; i < tam; i++){
        sprintf(elemento, "%d", v[i]);
        strcat(saida, elemento);
        if(i<tam-1) strcat(saida, ",");
    }
    strcat(saida, "]");
}

/***********************************************
* IMPLEMENTACAO
************************************************/

// EXERCICIO 1
void inverte_string(char* str){
    char aux;
    int tamanho = 0;
    for (int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }
    for (int i = 0; i < tamanho/2; i++){
        aux = str[i];
        str[i] = str[tamanho - 1 - i];
        str[tamanho - 1 - i] = aux;
    }
}

// EXERCICIO 2
int qtde_vogais1(char* str){
    int aux = 0, i, j;
    int tamanho = 0;
    for (int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }
    char vogais[] = "AaEeIiOoUu";
    for(i = 0; i < str[i]!='\0'; i++){
        for(j = 0; j < str[j]!='\0'; j++){
            if(str[i] == vogais[j]){
                aux++;
            }
        }
    }
    return aux;
}

int qtde_vogais2(char* str, int* saida){
    int aux = 0, i, j;
    char vogais[] = "AaEeIiOoUu";
    int tamanho = 0;
    for (int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }

    for(i = 0; i < str[i]!='\0'; i++){
        for(j = 0; j < str[j]!='\0'; j++){
            if(str[i] == vogais[j]){
                aux++;
            }
        }
    }
    *saida = aux;
}

// EXERCICIO 3
char* copia_string(char* str){
    int tamanho = 0;

    for (int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }

    char* copia = (char*) calloc(tamanho, sizeof(char));

    for(int i = 0; str[i] != '\0'; i++){
        copia[i] = str[i];
    }

    return copia;
}

// EXERCICIO 4
int* cria_vetor1(int tam, int valor){
    int* vetor = (int*) calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor[i] = valor;
    }
    return vetor;
}

bool cria_vetor2(int tam, int valor, int** saida){
    if(tam <= 0){
        return false;
    } else{
        int* vetor = (int*) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            vetor[i] = valor;
        }
        *saida = vetor;
        return true;
    }
}

// EXERCICIO 5
int* clone1(int *v, int tam){
    int* vetor_copia = (int*) calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor_copia[i] = v[i];
    }
    return vetor_copia;
}

bool clone2(int *v, int tam, int** saida){
    if(tam <= 0){
        return false;
    } else{
        int* vetor_copia = (int*) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            vetor_copia[i] = v[i];
        }
        *saida = vetor_copia;
        return true;
    }
}

// EXERCICIO 6
int* aleatorio1(int tam){
    int* vetor = (int*) calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 10;
    }
    return vetor;
}

bool aleatorio2(int tam, int** saida){
    if(tam < 0){
        return false;
    } else{
        int* vetor = (int*) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            vetor[i] = rand() % 10;
        }
        *saida = vetor;
        return true;
    }
}

//EXERCICIO 7
int dobra_tamanho(int** v, int tam){
    int* vetor = (int*) calloc(tam*2, sizeof(int));
    for(int i = 0; i < tam*2; i++){
        if(i<tam){
            vetor[i] = *(*v + i);
        } else{
            vetor[i] = 0;
        }
    }
    free(*v);
    *v = vetor;
    return tam*2;
}

//EXERCICIO 8
int** cria_matriz(int linhas, int colunas, int valor){
    int** m = (int**) calloc(linhas, sizeof(int*));
    for(int i = 0; i < linhas; i++){
        m[i] = (int*)calloc(colunas, sizeof(int));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            m[i][j] = valor;
        }
    }
    return m;
}