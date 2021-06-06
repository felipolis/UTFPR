#include <stdio.h>

int main(){

    int eleitores = 0;
    int candidato1 = 0, candidato2 = 0, candidato3 = 0, candidato4 = 0, nulo = 0, branco = 0;
    int votantes = 0;
    int voto;

    printf("Digite a quantidade total de eleitores: ");
    scanf("%d", &eleitores);

    while(votantes < eleitores){
        printf("Hora da Votacao! \nDigite 1 para votar no candidato 1 \nDigite 2 para votar no candidato 2 \nDigite 3 para votar no candidato 3 \nDigite 4 para votar no candidato 4 \nDigite 5 para votar Nulo \nDigite 6 para votar em Branco\n");
        scanf("%d", &voto);

        if(voto == 1){
            candidato1 = candidato1 + 1;
        } else if (voto == 2){
            candidato2 = candidato2 + 1;
        } else if (voto == 3){
            candidato3 = candidato3 + 1;
        } else if (voto == 4){
            candidato4 = candidato4 + 1;
        } else if (voto == 5){
            nulo = nulo + 1;
        } else if (voto == 6){
            branco = branco + 1;
        }

        votantes = votantes + 1;

    }

    printf("O candidato 1 teve %d votos!\n", candidato1);
    printf("O candidato 2 teve %d votos!\n", candidato2);
    printf("O candidato 3 teve %d votos!\n", candidato3);
    printf("O candidato 4 teve %d votos!\n", candidato4);
    printf("Houve %d votos Nulos!\n", nulo);
    printf("Houve %d votos Brancos!\n", branco);

    return 0;
}
