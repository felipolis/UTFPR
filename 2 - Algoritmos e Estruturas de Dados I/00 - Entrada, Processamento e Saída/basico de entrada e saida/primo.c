/* Número Primo
Na matemática, um Número primo é aquele que pode ser dividido somente por 1 (um) e por ele mesmo. Por exemplo, o número 7 é primo, pois pode ser dividido apenas pelo número 1 e pelo número 7.

Entrada
A entrada contém vários casos de teste. A primeira linha da entrada contém um inteiro N (1 ≤ N ≤ 100), indicando o número de casos de teste da entrada. Cada uma das N linhas seguintes contém um valor inteiro X (1 < X ≤ 107), que pode ser ou não, um número primo.

Saída
Para cada caso de teste de entrada, imprima a mensagem "X eh primo" ou "X nao eh primo", de acordo com a especificação fornecida.

Exemplos
Veja alguns exemplos de casos de teste para validar sua solução. */

#include <stdio.h>

void calculo_primo(int tam, int lista[]){
    int i, j, aux;
    for(i = 0; i < tam; i++){
        aux = 0;
        for(j = 1; j <= lista[i]; j++){
            if(lista[i] % j == 0){
                aux++;
            }
        }
        if(aux == 2){
            printf("%d eh primo\n", lista[i]);
        } else{
            printf("%d nao eh primo\n", lista[i]);
        }
        
    }
}

int main(){

    int n = 1;
    int i;
    int numeros[100];

    //ENTRADA

    do{
        scanf("%d", &n);
    } while (n <= 1 || n > 107);   

    for(i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
    }
    
    //PROCESSAMENTO E SAIDA

    calculo_primo(n, numeros);

    return 0;
}