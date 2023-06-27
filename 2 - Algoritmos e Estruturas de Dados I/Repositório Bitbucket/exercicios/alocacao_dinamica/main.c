#include<stdio.h>
#include "lista_alocacao_dinamica.c"


void teste_exemplo(){
    int v1[4] = {1,2,3,4};
    int v2[2] = {5,6};
    char temp[200];
    toString_vetor(v1, 4, temp);
    printf("%s\n", temp);
    toString_vetor(v2, 2, temp);
    printf("%s\n", temp);
}

void teste_ex01(){
    // char nome[20] = "Rafael Liberato";
    // inverte_string(nome);
    // printf("%s\n", nome); 
}


int main(){
    
    teste_exemplo();
    // teste_ex01();
    // teste_ex02();
    // teste_ex03();
    // teste_ex04();
    // teste_ex05();
    
    return 0;
}