#include "tad_vetor.h"

int main(){

    //1. Criar um novo vetor
    Vetor* v1 = vet_criar(3);

    //2. Inserir um elemento no final da sequência
    vet_anexar(v1, 2);
    vet_imprimir(v1);

    vet_anexar(v1, 3);
    vet_imprimir(v1);

    vet_anexar(v1, 8);
    vet_imprimir(v1);

    vet_anexar(v1, 7);
    vet_imprimir(v1);

    //3. Inserir um elemento em qualquer posição da sequência
    vet_inserir(v1, 4, 1);
    vet_imprimir(v1);

    vet_inserir(v1, 9, 3);
    vet_imprimir(v1);

    //4. Substituir um elemento em uma determinada posição
    vet_substituir(v1, 4, 0);
    vet_imprimir(v1);

    //5. Remover um elemento de uma determinada posição
    int valor;
    vet_removerPosicao(v1, 2, &valor);
    printf("vet_removerPosicao = %d\n", valor);
    vet_imprimir(v1);

    //6. Remover um elemento de acordo com o seu valor.
    int valor1 = vet_removerElemento(v1, 0);
    printf("vet_removerElemento = %d\n", valor1);
    vet_imprimir(v1);

    //7. Recuperar quantos elementos estão armazenados na sequência.
    int tam = vet_tamanho(v1);
    printf("Tamanho do vetor = %d\n", tam);

    //8. Recuperar qual elemento está armazenado em uma determinada posição
    int valor2;
    vet_elemento(v1, 3, &valor2);
    printf("vet_elemento = %d\n", valor2);

    //9. Recuperar a posição em que um determinado elemento está armazenado. Caso haja valores repetidos, recuperar a primeira ocorrência.
    int valor3 = vet_posicao(v1, 7);
    printf("vet_posicao = %d\n", valor3);

    //12. Devolve o vetor na forma de String
    char string[100];
    vet_toString(v1, string);
    printf("string = %s\n", string);




    return 0;
}