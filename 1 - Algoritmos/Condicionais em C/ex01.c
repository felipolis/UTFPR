#include <stdio.h>

int main() {
int n1, n2;

printf("Digite um numero: ");
scanf("%d", &n1);

printf("Digite outro numero: ");
scanf("%d", &n2);

if(n1 == n2){
    printf("Os numeros sao iguais!");
} else if( n1 > n2){
    printf("%d e o maior numero!", n1);
} else {
    printf("%d e o maior numero!", n2);
}

return 0;
}