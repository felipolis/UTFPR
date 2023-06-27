#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int ra;
    char nome[12];
    float notas[2];
} Aluno;

void imprimeAluno(Aluno* a) {
    printf("RA    : %d\n", a->ra);
    printf("Nome  : %s\n", a->nome);
    printf("Nota 1: %.2f\n", a->notas[0]);
    printf("Nota 2: %.2f\n", a->notas[1]);
    printf("\n");
}

int main(void) {
    // Alocando memória
    Aluno a1;

    Aluno* a2;
    a2 = (Aluno*)malloc(sizeof(Aluno));

    // Manipulando dados
    a1.ra = 1;
    strcpy(a1.nome, "Joao");
    a1.notas[0] = 7.0;
    *(a1.notas + 1) = 8.0;

    *a2 = a1;
    (*a2).ra = 2;
    strcpy(a2->nome, "Maria");
    a2->notas[0] = 8.0;
    *(a2->notas + 1) = 9.0;

    // Passando uma struct por parâmetro
    imprimeAluno(&a1);
    imprimeAluno(a2);

    //Liberando memória
    free(a2);
}