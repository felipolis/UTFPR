#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "pilha.h"

int main(){

    int elemento;
    char str[200];

    Pilha* p1 = pilha_criar();
    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 30);

    pilha_toString(p1, str);
    printf("%s\n", str); //[10,20,30]

    pilha_desempilhar(p1, &elemento);
    printf("retirei: %d\n", elemento);

    pilha_toString(p1, str);
    printf("%s\n", str); 

    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 30);

    pilha_toString(p1, str);
    printf("%s\n", str); 

    pilha_empilhar(p1, 40);
    pilha_empilhar(p1, 50);
    pilha_empilhar(p1, 60);
    pilha_empilhar(p1, 70);

    pilha_toString(p1, str);
    printf("%s\n", str); 

    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);
    pilha_desempilhar(p1, &elemento);


    pilha_toString(p1, str);
    printf("%s\n", str); 

    pilha_desempilhar(p1, &elemento);
    printf("retirei: %d\n", elemento);

    pilha_toString(p1, str);
    printf("%s\n", str);


    return 0;
}