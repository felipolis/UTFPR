#include "lista.h"

int main(){

    Lista* l = lista_criar();
    char lista[200];

    lista_anexar(l, 10);
    lista_anexar(l, 20);

    lista_toString(l,lista);
    printf("%s\n", lista);

    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);
    lista_anexar(l, 60);
    lista_anexar(l, 70);
    lista_anexar(l, 80);

    lista_toString(l,lista);
    printf("%s\n", lista);

    int tam = lista_tamanho(l);
    printf("TAM %d\n", tam);

    lista_substituir(l,2,300);
    lista_toString(l,lista);
    printf("%s\n", lista);

    int pos = lista_posicao(l,70);
    printf("POS 70: %d\n", pos);

    int elemento;
    lista_buscar(l,-1,&elemento);
    printf("ELEMENTO pos -1: %d\n", elemento);

    lista_removerElemento(l, 60);
    lista_toString(l,lista);
    printf("%s\n", lista);

    lista_inserir(l,1000,2);
    lista_toString(l,lista);
    printf("%s\n", lista);

    lista_inserir(l,-90,0);
    lista_toString(l,lista);
    printf("%s\n", lista);

    lista_inserir(l,-999,9);
    lista_toString(l,lista);
    printf("%s\n", lista);

    lista_removerPosicao(l,3,&pos);
    lista_toString(l,lista);
    printf("%s\n", lista);
    printf("ELEM REM:%d\n", pos);

    lista_destruir(&l);



    return 0;
}