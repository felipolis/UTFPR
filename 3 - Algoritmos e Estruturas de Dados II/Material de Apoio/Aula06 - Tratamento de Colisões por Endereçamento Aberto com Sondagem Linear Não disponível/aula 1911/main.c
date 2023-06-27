#include "tabelahash_ea.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFFER 20
#define DEBUG

int main(int argc, char* argv){
    char buffer[TAM_BUFFER];
    int n, m; //n discos do jack, m discos da jill
    int repetidos = 0;
    int i;
    int id;

    THEA* th;

    fgets(buffer, TAM_BUFFER, stdin);
    n = atoi(strtok(buffer, " "));
    m = atoi(strtok(NULL, " \n"));

    while((n != 0) || (m != 0)){
        repetidos = 0;
        
        #ifdef DEBUG
        printf("n = %d m = %d\n", n, m);
        #endif

        th = THEA_Criar(5, FS_LINEAR);

        for(i = 0; i < n; i++){
            fgets(buffer, TAM_BUFFER, stdin);
            id = atoi(buffer);
            THEA_Inserir(th, id, id);
        }

        for(i = 0; i < m; i++){
            fgets(buffer, TAM_BUFFER, stdin);
            id = atoi(buffer);
            if(THEA_Buscar(th, id) != -1){
                repetidos++;
            }
        }

        #ifdef DEBUG
        printf("discos em comum: %d\n", repetidos);
        #else
        printf("%d\n", repetidos);
        #endif

        fgets(buffer, 30, stdin);
        n = atoi(strtok(buffer, " "));
        m = atoi(strtok(NULL, " \n")); 
    }

}
