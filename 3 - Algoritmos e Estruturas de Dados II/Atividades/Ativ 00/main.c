#include <stdio.h>
#include "pilha.h"

//-------------------------------VARIAVEIS GLOBAIS-----------------------------------
#define LIVRE 0
#define PAREDE 1
#define PASSEI 8

#define BAIXO 4
#define DIREITA 5
#define CIMA 3
#define ESQUERDA 2

Pilha *pLinha;
Pilha *pColuna;
Pilha *pDirecao;
char caminho[100];
bool posInicial = true;
bool ganhei = false;

//------------------------------------FUNÇÕES------------------------------------------
int explorar(int** mapa, int linha, int coluna){
    //printf("%d ",linha);
    //printf("%d\n",coluna);


    //Primeira posição
    if(posInicial){
        mapa[linha][coluna] = PASSEI;
        pilha_empilhar(pLinha, linha);
        pilha_empilhar(pColuna, coluna);
        posInicial = false;
    }

    //Resto do codigo
    if (linha == 9 && coluna == 9){

        ganhei = true;
        return 0;

    } else{

        if (linha + 1 <= 9 && mapa[linha + 1][coluna] == LIVRE){ //BAIXO

            printf("Da para ir para baixo\n");
            linha++;                            //Se movimenta para baixo
            pilha_empilhar(pLinha, linha);      //Empilha a posLinha
            pilha_empilhar(pColuna, coluna);    //Empilha a posColuna
            pilha_empilhar(pDirecao, BAIXO);    //Empilha a direção

            mapa[linha][coluna] = PASSEI;       //Marcando a posição

            explorar(mapa, linha, coluna);      //Recursividade



        } else if(coluna + 1 <= 9 && mapa[linha][coluna + 1] == LIVRE){ //DIREITA


            printf("Da para ir para direita\n");
            coluna++;
            pilha_empilhar(pLinha, linha);
            pilha_empilhar(pColuna, coluna);
            pilha_empilhar(pDirecao, DIREITA);
            
            mapa[linha][coluna] = PASSEI;

            //printf("%d ",linha);
            //printf("%d\n",coluna);

            explorar(mapa, linha, coluna);


        } else if(linha - 1 >= 0 && mapa[linha - 1][coluna] == LIVRE){  //CIMA


            printf("Da para ir para cima\n");
            linha--;
            pilha_empilhar(pLinha, linha);
            pilha_empilhar(pColuna, coluna);
            pilha_empilhar(pDirecao, CIMA);

            mapa[linha][coluna] = PASSEI;

            explorar(mapa, linha, coluna);


        } else if(coluna - 1 >= 0 && mapa[linha][coluna-1] == LIVRE){   //ESQUERDA

            printf("da p ir pra esquerda\n");
            coluna--;
            pilha_empilhar(pLinha, linha);
            pilha_empilhar(pColuna, coluna);
            pilha_empilhar(pDirecao, ESQUERDA);

            mapa[linha][coluna] = PASSEI;

            explorar(mapa, linha, coluna);

        } else{

            printf("Voltando...\n");
            int auxLinha = -1;
            int auxColuna = -1;
            int auxDirecao = -1;
            pilha_desempilhar(pLinha, &auxLinha);
            pilha_desempilhar(pColuna, &auxColuna);
            pilha_desempilhar(pDirecao, &auxDirecao);

            pilha_topo(pLinha, &auxLinha);
            pilha_topo(pColuna, &auxColuna);
            linha = auxLinha;
            coluna = auxColuna;
            //printf("%d  %d\n", linha, coluna);

            //Voltou ao inicio
            if(linha == 0 && coluna == 0){
                ganhei = false;
                return 0;
            }

            explorar(mapa, linha, coluna);
            

        }
    }
}

void imprimir_caminho(Pilha* pCaminho){
    int aux = 0;
    int qtde = pilha_quantidade(pCaminho);
    int* vet_caminho = (int*) calloc(qtde, sizeof(int));

    //String para vetor
    int i = 0;
    while(!pilha_vazia(pCaminho)){
        pilha_desempilhar(pCaminho, &aux);
        vet_caminho[i] = aux;
        i++;
    }

    //imprimindo
    for(int j = qtde; j >= 0; j--){
        if(vet_caminho[j] == 4) printf("BAIXO");
        if(vet_caminho[j] == 5) printf("DIREITA");
        if(vet_caminho[j] == 3) printf("CIMA");
        if(vet_caminho[j] == 2) printf("ESQUERDA");
        if(j > 0) printf(" -> ");
    }
}

//------------------------------------FUNÇÃO MAIN------------------------------------------
int main(){

    //ALOCANDO AS PILHAS
    pLinha = pilha_criar();
    pColuna = pilha_criar();
    pDirecao = pilha_criar();

    //CONTRUÇÃO DO MAPA DO LABIRINTO
    int mapa[10][10] = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}};

    int** m;
    m =(int**)calloc(10, sizeof(int*));
    m[0] = (int*)calloc(10, sizeof(int));
    m[1] = (int*)calloc(10, sizeof(int));
    m[2] = (int*)calloc(10, sizeof(int));
    m[3] = (int*)calloc(10, sizeof(int));
    m[4] = (int*)calloc(10, sizeof(int));
    m[5] = (int*)calloc(10, sizeof(int));
    m[6] = (int*)calloc(10, sizeof(int));
    m[7] = (int*)calloc(10, sizeof(int));
    m[8] = (int*)calloc(10, sizeof(int));
    m[9] = (int*)calloc(10, sizeof(int));

    m[0] = mapa[0];
    m[1] = mapa[1];
    m[2] = mapa[2];
    m[3] = mapa[3];
    m[4] = mapa[4];
    m[5] = mapa[5];
    m[6] = mapa[6];
    m[7] = mapa[7];
    m[8] = mapa[8];
    m[9] = mapa[9];


    //ENTRANDO NO LABIRINTO
    explorar(m, 0, 0);


    //MAPA DO LABIRINTO
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d  ", m[i][j]);
        }
        printf("\n\n");
    }

    //GANHEI OU PERDI?
    if(ganhei){
        printf("Ganhei!!!\n");
        imprimir_caminho(pDirecao);
        printf("\n");
    } else{
        printf("Nao existe um caminho para a saida!");
    }

    /* ARRAYS
    pilha_toString(pDirecao, caminho);
    printf("%s\n", caminho);
    pilha_toString(pLinha, caminho);
    printf("%s\n", caminho);
    pilha_toString(pColuna, caminho);
    printf("%s\n", caminho);
    */

    return 0;
}



/*  Made By: Felipe Archanjo

    Signature:                                                           
                                                    `-                          
               `                                  .. - `.`                      
               ..``-` .                         .-``:..`-                       
                . `-`.-.                      `-. .:` ..                        
                 . `.`-`.                   `..``.` .-`                         
                 `. ``- -                 `..```` `-:.`-                        
                 `:. -.--              ``.-.```` ``.``:--                       
                  .-`--:--           `::-.-`` `.`` `.-.-`                       
                   .-.-`/`.         `-.-`` `  ``.....--.`                       
                    :-:...-`       .. `````-   `.  ```..                        
                    :`-.:-`.      `.  ```` `.    ```-.`                         
                    :  `-..-      -     ``` `    `.`./:`                        
                    .   `----     -     `..   `  `` ...`                        
                    ``   ``::`    -     .`    ` ```-::..                        
                     ..   ..:.    .    `.    `` ```.--.`                        
               `///-..:--:.//`    -       `... ``..`..-                         
                `:+-```.-`-/:-    .          ```  `-:-.                         
                 `o/ ./:-`o::-` `.       `` `.```.--:`                          
                  /:.`...`-:::..`       ..  `.....--                            
                  `:-:-```  `/`        `-. ...`.-..`                            
                    -`      `.` `      -- `--..--`                              
                    -.      ``` --..``-- `-.`.:-`                               
                     :`      `  ..-.`-`.:`./::-`                                
                     .:`   `.    .::--:-::-.`                                   
                      --`-`-    .   ..`.`-       `....`                         
                       .-`-/.  `-  -.```..-     .///////-                       
                        ----o`.:: -`     `/`    `.`   `++:                      
                         +//o///--/       `/           //+                      
                         -+/s+//`./-`     `o:.```````-:++.                      
                         `o+y/+o/::++::.`.:+/+++////++/-`                       
                         +soso+.``-++:--..  `.......`                           
                           `.-.                                                 
*/