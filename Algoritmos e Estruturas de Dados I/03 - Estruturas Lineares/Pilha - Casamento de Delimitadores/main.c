#include "pilha.h"

bool compativeis(char exp, char topo){
    char abre[3] = "([{";
    char comp_abre[3] = ")]}";
    int pos;

    for(int i = 0; abre[i] != '\0'; i++){ //pegar indice do topo
        if(topo == abre[i]){
            pos = i;
            break;
        }
    }

    return (comp_abre[pos] == exp ? true : false);
}

int main(){

    int quantidade_expressoes;
    char expressao[200];
    char aux;
    char topo;
    char desempilhado;
    
    scanf("%d", &quantidade_expressoes);

    for(int i = 0; i < quantidade_expressoes; i++){

        Pilha* p = pilha_criar();
        scanf("\n%[^\n]", expressao);
        bool correto = true;

        for(int j = 0; expressao[j] != '\0'; j++){
            if(expressao[j] == '(' || expressao[j] == '[' || expressao[j] == '{'){
                pilha_empilhar(p, expressao[j]);
            }

            if(expressao[j] == ')' || expressao[j] == ']' || expressao[j] == '}'){
                if(!pilha_vazia(p)){
                    pilha_desempilhar(p, &desempilhado);

                    if(!compativeis(expressao[j], desempilhado)){
                        printf("%d\n", - 1);
                        correto = false;
                        break;
                    }

                }else{
                    printf("%d\n", -3);
                    correto = false;
                    break;
                }
            }

            if(!pilha_vazia(p) && j == strlen(expressao) - 1){
                printf("%d\n", -2);
                correto = false;
                break;
            }
        }
        if(correto){
            printf("%d\n", 1);
        }
        pilha_destruir(&p);
    }

    return 0;
}