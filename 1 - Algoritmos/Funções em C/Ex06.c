#include <stdio.h>

///Funcao alfabeto

int alfabeto(int n){

    if(n==97 || n==101 || n==105 || n==111 || n==117 || n==65 || n==69 || n==73 || n==79 || n==85){

        return 0;

    } else if(((n>=97 && n<=122) && (n!=97 || n!=101 || n!=105 || n!=111 || n!=117)) || ((n>=65 && n<=90) && (n!=65 || n!=69 || n!=73 || n!=79 || n!=85))){

        return 1;

    } else{

        return -1;

    }

}

///Funcao main

int main(){

    char letra;

    printf("Digite um caractere: ");
    scanf("%c", &letra);

    printf("%d", alfabeto(letra));


    return 0;
}
