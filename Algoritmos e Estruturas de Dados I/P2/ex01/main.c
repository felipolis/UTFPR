#include <stdio.h>
#include <string.h>

#include "fila.h"

int main(){
    char str[300];
    Fila* f1 = fila_criar(-1);
    fila_inserir(f1, 10);
    fila_inserir(f1, 50);
    fila_inserir(f1, 30);
    fila_inserir(f1, 40);
    fila_inserir(f1, 20);

    fila_toString(f1, str);
    printf("%s\n", str);

    Fila* f2 = fila_criar(1);
    fila_inserir(f2, 10);
    fila_inserir(f2, 50);
    fila_inserir(f2, 30);
    fila_inserir(f2, 40);
    fila_inserir(f2, 20);

    fila_toString(f2, str);
    printf("%s\n", str);


    
    

}