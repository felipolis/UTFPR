#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

void ler_arquivo1(char* nome_arq){
    FILE* arq;

    arq = fopen(nome_arq, "r");

    if(arq == NULL){
        printf("erro ao acessar o arquivo %s\n", "entrada.txt");
        exit(EXIT_FAILURE);
    }

    int x[4];

    fscanf(arq, "%d %d %d %d\n", &x[0], &x[1], &x[2], &x[3]);

    printf("%d %d %d %d\n", x[0], x[1], x[2], x[3]);

    printf("a soma dos números que estavam no arquivo é %d\n", x[0] + x[1] + x[2] + x[3]);

    fclose(arq);    
}

void ler_arquivo2(char *nome_arq){
    FILE* arq;

    arq = fopen(nome_arq, "r");

    if(arq == NULL){
        printf("erro ao acessar o arquivo %s\n", "entrada.txt");
        exit(EXIT_FAILURE);
    }

    int x[4];
    int soma = 0;
    while(!feof(arq)){
        fscanf(arq, "%d %d %d %d\n", &x[0], &x[1], &x[2], &x[3]);
        printf("%d %d %d %d\n", x[0], x[1], x[2], x[3]);
        soma += (x[0]+ x[1] + x[2] + x[3]);
    }

    printf("a soma dos números que estavam no arquivo é %d\n", soma);

    fclose(arq);     
}

void ler_arquivo3(char *nome_arq){
    FILE* arq;

    arq = fopen("entrada.txt", "r");

    if(arq == NULL){
        printf("erro ao acessar o arquivo %s\n", "entrada.txt");
        exit(EXIT_FAILURE);
    }

    char buffer[50];
    char *p;

    fgets(buffer, 50, arq);

    int soma = 0;

    p = strtok(buffer, " \n");
    while(p != NULL){
        printf("%s ", p);
        soma += atoi(p);
        p = strtok(NULL, " \n");
    }
    printf("\n");

    printf("a soma dos números que estavam no arquivo é %d\n", soma);

    fclose(arq);    
}

void ler_arquivo4(char* nome_arq){
    FILE* arq;

    arq = fopen("entrada2.txt", "r");

    if(arq == NULL){
        printf("erro ao acessar o arquivo %s\n", "entrada.txt");
        exit(EXIT_FAILURE);
    }

    char buffer[50];
    char *p;
    int soma = 0;

    fgets(buffer, 50, arq);
    do{
        p = strtok(buffer, " \n");
        while(p != NULL){
            printf("%s ", p);
            soma += atoi(p);
            p = strtok(NULL, " \n");
        }
        printf("\n");
        fgets(buffer, 50, arq);
    }while(!feof(arq));

    printf("a soma dos números que estavam no arquivo é %d\n", soma);

    fclose(arq);      
}

void escrever_registros(char* nome_arq){
    Pessoa pessoas[] = {
        {"Juliano", 34, "999.999.999-99", "99.999.999-9"},
        {"Gabriel", 32, "888.888.888-88", "88.888.888-8"},
        {"Marcos", 42, "777.777.777-77", "77.777.777-7"}
    };
    
    FILE *arq = fopen("pessoas.dat", "wb");

    int n = 3;

    fwrite(&n, sizeof(int), 1, arq);

    fwrite(pessoas, sizeof(Pessoa), n, arq);

    fclose(arq);    
}

int main(int argc, char** argv){
    int n;
    Pessoa* pessoas;

    FILE* arq = fopen("pessoas.dat", "rb");

    fread(&n, sizeof(int), 1, arq);

    pessoas = malloc(sizeof(Pessoa) * n);

    fread(pessoas, sizeof(Pessoa), n, arq);

    int i;
    for(i = 0; i < n; i++){
        printf("%s, %d anos, cpf: %s, rg: %s\n", 
            pessoas[i].nome, pessoas[i].idade, 
            pessoas[i].cpf, pessoas[i].rg);
    }

    fclose(arq);

    return(EXIT_SUCCESS);
}