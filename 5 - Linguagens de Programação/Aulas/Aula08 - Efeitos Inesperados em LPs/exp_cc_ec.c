#include <stdio.h>

int funcao1() {
    printf("Executando função 1\n");
    return 0;
}

int funcao2() {
    printf("Executando função 2\n");
    return 1;
}

int main() {
    if (funcao1() && funcao2()) {
        printf("Expressão verdadeira\n");
    } else {
        printf("Expressão falsa\n");
    }
}
