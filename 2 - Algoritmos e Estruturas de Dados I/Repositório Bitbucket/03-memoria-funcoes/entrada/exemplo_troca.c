#include<stdio.h>

typedef struct aluno{
    int ra;
    char nome[20];
    float notas[2];
}Aluno;

// Troca entre valores inteiros
void troca_inteiros(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;    
}

// Troca entre caracteres
void troca_caractere(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Troca entre caracteres



int main(){
    int n1 = 10;
    int n2 = 200;
    // [TODO] Troca de valores entre variáveis n1 e n2
    troca_inteiros(&n1, &n2);
    
    printf("n1: %d\n", n1);
    printf("n2: %d\n", n2);
    printf("---\n");

    // Troca de valores entre posições em um vetor
    int v[3] = {100,200,300};
    // [TODO] trocar a posição 1 com a 2
    troca_inteiros(v+1, v+2);
    // troca_inteiros(&v[1], &v[2]);
    printf("[%d, %d, %d]\n", v[0], v[1], v[2]);
    printf("---\n");
    
    // Troca de caracteres no nome da struct aluno
    Aluno a1 = {1, "Joao da Silva", {9.5, 9.2}};
    // [TODO] trocar o caractere 2 com o 3
    troca_caractere(a1.nome+2, a1.nome+3);
    printf("%s\n", a1.nome);

    


    return 0;
}