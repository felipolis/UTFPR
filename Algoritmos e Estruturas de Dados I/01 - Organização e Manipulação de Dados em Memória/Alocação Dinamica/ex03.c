#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main(){

    char texto[] = "Eu amo Programacao";
    char* str = copia_string(texto);
    printf("%s\n", str);

    return 0;
}