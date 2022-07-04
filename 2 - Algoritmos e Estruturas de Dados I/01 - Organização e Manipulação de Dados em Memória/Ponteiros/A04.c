#include <stdio.h>

int main(){

    int num_linhas = 4;
    int num_colunas = 2;
    int m[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int* p = (int*)m;
    int* w = (int*)m + 6;

    printf("----------------\n");

    printf("m - %d\n", m);
    printf("m[0] - %d\n", m[0]);
    printf("p - %d\n", p);
    printf("m+1 - %d\n", m+1);
    printf("m[1] - %d\n", m[1]);
    printf("p+3 - %d\n", p+3);
    printf("m[0][0] - %d\n", m[0][0]);
    printf("*m[0] - %d\n", *m[0]);
    printf("*p - %d\n", *p);
    printf("p[0] - %d\n", p[0]);
    printf("m[3][1] - %d\n", m[3][1]);
    printf("*(m[3]+1) - %d\n", *(m[3]+1));
    printf("*(p+(3*2)+1) - %d\n", *(p+(3*2)+1));
    printf("w[1] - %d\n", w[1]);
    printf("*(w+1) - %d\n", *(w+1));

    printf("----------------\n");

    for(int i = 0; i < num_linhas; i++){
        for(int j = 0; j < num_colunas; j++){
            printf("Endereco &m[%d][%d] = %d\n", i, j, &m[i][j]);
            printf("Valor     m[%d][%d] = %d\n\n", i, j, m[i][j]);
        }
    }

    for(int i = 0; i < num_linhas; i++){
        for(int j = 0; j < num_colunas; j++){
            printf("Endereco &m[%d][%d] = %d\n", i, j, p+(i*num_colunas)+j);
            printf("Valor     m[%d][%d] = %d\n\n", i, j, *(p+(i*num_colunas)+j));
        }
    }

    return 0;
}