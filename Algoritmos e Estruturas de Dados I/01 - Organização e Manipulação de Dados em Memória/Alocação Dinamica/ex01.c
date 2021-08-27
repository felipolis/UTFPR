#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main(){

    char nome[] = "Ana Julia da Silva";
    inverte_string(nome);
    printf("%s", nome);

    return 0;
}