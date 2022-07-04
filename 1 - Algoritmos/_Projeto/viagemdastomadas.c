#include <stdio.h>

int main() {
    //Declaração de variaveis
    int t1;
    int t2;
    int t3;
    int t4;
    int total;

    //Criação do ponteiro e leitura do arquivo
    FILE *entrada;
    entrada = fopen("entrada.txt", "r");

    //Lendo dados do arquivo
    if(entrada == NULL){

        printf("Erro ao abrir o arquivo!");

    }else{

        fscanf(entrada, "%d %d %d %d", &t1, &t2, &t3, &t4);

        if((t1>1 && t1<7) && (t2>1 && t2<7) && (t3>1 && t3<7) && (t4>1 && t4<7)){
            total = (t1+t2+t3+t4) - 3;
            printf("Tomadas que podem ser usadas: %d", total);
        } else{
            printf("Input Invalido! Insira elementos entre o intervalo [2,6]");
        }
        fclose(entrada);
    }

    return 0;
}

