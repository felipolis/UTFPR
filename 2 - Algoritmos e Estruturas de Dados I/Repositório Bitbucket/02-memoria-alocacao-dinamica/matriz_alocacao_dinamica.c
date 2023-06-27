#include <stdio.h>
#include <stdlib.h>

void imprimeEST1(int* m, int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("\t%d", m[i * colunas + j]);
        }
        printf("\n");
    }
}

void imprimeEST2(int l, int c, int m[l][c]) {
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
}

void imprimeDIN(int** m, int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // Criando matriz
    int m1[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int** m2;
    m2 = (int**)calloc(2, sizeof(int*));
    m2[0] = (int*)calloc(3, sizeof(int));
    m2[1] = (int*)calloc(3, sizeof(int));

    // MANIPULANDO OS DADOS
    m1[0][0] = 10;
    *(m1[1] + 2) = 60;

    m2[0][0] = 10;
    *(m2[1] + 2) = 60;

    // PASSANDO POR PARAMETRO
    imprimeEST1((int*)m1, 2, 3);
    printf("\n");
    imprimeEST2(2, 3, m1);
    printf("\n");

    imprimeDIN(m2, 2, 3);
    printf("\n");

    // DESALOCANDO A MATRIZ
    free(m2[0]);
    free(m2[1]);

    free(m2);
    m2 = NULL;
}