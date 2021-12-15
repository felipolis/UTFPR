#include <stdlib.h>
#include "hashtable_ea.h"

int THEA_Hash(THEA *TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA *THEA_Criar(int m)
{
    THEA *novo = (THEA *)malloc(sizeof(THEA));
    novo->TH = (ELEM *)malloc(sizeof(ELEM) * m);
    novo->m = m;
    novo->n = 0;

    for (int i = 0; i < m; i++)
    {
        novo->TH[i].estado = E_LIVRE;
    }

    return novo;
}

int THEA_Inserir(THEA *TH, int chave, int valor){
    int k = 0;
    int h = THEA_Hash(TH, chave, k);
    int h_inicial = h;

    while (TH->TH[h].estado == E_OCUPADO){

        if (TH->TH[h].chave == chave){

            break;

        } else{

            k++;
            h = THEA_Hash(TH, chave, k);

            if (h == h_inicial){
                return -1;
            }

        }
    }

    if(TH->TH[h].chave != chave){
        TH->n++;
    }
    TH->TH[h].chave = chave;
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;

    return h;
}

int THEA_Buscar(THEA *TH, int chave){
    int k = 0;
    int h = THEA_Hash(TH, chave, k);
    int h_inicial = h;

    while (TH->TH[h].estado != E_LIVRE){

        if(TH->TH[h].estado == E_OCUPADO && TH->TH[h].chave == chave){
            return h;
        } else{
            k++;
            h = THEA_Hash(TH, chave, k);

            if (h == h_inicial){
                return -1;
            }
        }
    }
    return -1;
}

void THEA_Remover(THEA *TH, int chave){
    
    int p = THEA_Buscar(TH, chave);
    if(p != -1){
        TH->TH[p].estado = E_APAGADO;
        TH->n--;
    }

}

void THEA_Imprimir(THEA *TH){
    for (int i = 0; i < TH->m; i++){
        const char e = TH->TH[i].estado == E_OCUPADO ? 'O' : TH->TH[i].estado == E_LIVRE ? 'L' : 'A';
        printf("%d: %d, %c\n", i, TH->TH[i].chave, e);
    }
}

// RETORNA O TAMANHO DO MAIOR CLUSTER
int THEA_ClusterMaximo(THEA* TH){
    int maior = 0;
    int atual = 0;
    for (int i = 0; i < TH->m; i++){
        if(TH->TH[i].estado == E_OCUPADO){
            atual++;
        } else{
            if(atual > maior){
                maior = atual;
            }
            atual = 0;
        }
    }
    if(atual > maior){
        maior = atual;
    }
    return maior;
}

// RETORNA O TAMANHO MEDIO DOS CLUSTER
float THEA_TamMedioClusters(THEA* TH){
    int ocupados = 0;
    int livres = 0;
    bool emCluster = false;

    for (int i = 0; i < TH->m; i++){

        if(TH->TH[i].estado == E_OCUPADO){
            ocupados++;
            emCluster = true;
        } else{
            if(emCluster){
                livres++;
                emCluster = false;
            }
        }

    }

    return (float)ocupados / livres;
}

// RETORNA UM VETOR COM O TAMANHO DOS CLUSTERS
int* Vet_Tam_Clusters(THEA* TH, int* tam){

    bool emCluster = false;
    int quant_clusters = 0;
    
    //Contar quantos clusters existem
    for (int i = 0; i < TH->m; i++){

        if(TH->TH[i].estado == E_OCUPADO){
            emCluster = true;
        } else{
            if(emCluster){
                quant_clusters++;
                emCluster = false;
            }
        }

    }

    //Criar vetor de inteiros com o tamanho dos clusters
    int* vet_clusters = (int*)malloc(sizeof(int) * quant_clusters);

    int j = 0;
    int ocupados = 0;
    int livres = 0;
    emCluster = false;

    for (int i = 0; i < TH->m; i++){

        if(TH->TH[i].estado == E_OCUPADO){
            ocupados++;
            emCluster = true;
        } else{
            if(emCluster){
                vet_clusters[j] = ocupados;
                j++;
                ocupados = 0;
                emCluster = false;
            }
        }

    }

    *tam = quant_clusters;
    return vet_clusters;
}

float THEA_CustoBemSucedida (THEA* TH) {
    #define MAX(a,b) (a > b) ? a : b;

    int tam;
    float aux;
    float custo = 0;
    int* vet_clusters = Vet_Tam_Clusters(TH, &tam);


    for (int i = 0; i < tam; i++) {
        aux = MAX((float)vet_clusters[i]/2, 1);

        custo += aux/TH->n;
    }
    

    free(vet_clusters);
    return custo;
}