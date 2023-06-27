#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main(){

    char texto[100] = "UTFPR Campo Mourao";
    int n1 = qtde_vogais1(texto);
    int n2;
    qtde_vogais2(texto, &n2);
    printf("Vogais: %d\n", n1);
    printf("Vogais: %d\n", n2);

    return 0;
}