#include "tabelahash_ea.h"
#include <stdlib.h>
#include <stdio.h>

static int eh_primo(int n){
    int i;

    if (n<=1)
        return 0;
    if (n <= 3)
        return 1;

    if(n%2 == 0 || n%3 == 0)
        return 0;
    
    for(i = 5; i*i < n; i+=6){
        if((n%i == 0) || (n%(i+1) == 0) )
            return 0;
    }

    return 1;
}

// Pode retornar um primo menor caso n for muito próximo de INT_MAX!
static int prox_primo(int n){
    if(n<=1)
        return 2;

    while(1){
        n++;
        if(eh_primo(n))
            return n;
    }
}

static void THEA_Redimensionar(THEA* TH, int m_novo){
    ELEM *nova, *antiga;
    int i, m_antigo;

    nova = malloc(sizeof(ELEM) * m_novo);
    for(i = 0; i < m_novo; i++){
        nova[i].estado = E_LIVRE;
    }

    antiga = TH->TH;
    m_antigo = TH->m;
    TH->TH = nova;
    TH->m = m_novo;
    TH->n = 0;

    for(i = 0; i < m_antigo; i++){
        if(antiga[i].estado == E_OCUPADO){
            THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);
        }
    }

    free(antiga);

}


int THEA_Hash(THEA* TH, int chave, int k)
{
    // switch(TH->f_sondagem){
    //     case FS_LINEAR:
    //         return ((chave % TH->m) + k) % TH->m;
    //     case FS_QUADRATICA:
    //         return ((chave % TH->m) + k*k) % TH->m;
    //     case FS_HASH_DUPLO:
    //         return ((chave % TH->m) + k* ((chave % TH->s)+1)) % TH->m;
    // }
    return TH->hash(TH, chave, k);
    
}

int hash_linear(THEA* TH, int chave, int k){
    return ((chave % TH->m) + k) % TH->m;
}

int hash_quadratica(THEA* TH, int chave, int k){
    return ((chave % TH->m) + k*k) % TH->m;
}

int hash_duplo(THEA* TH, int chave, int k){
    return ((chave % TH->m) + k* ((chave % TH->s)+1)) % TH->m;
}

void dummy_callback_redim(THEA* TH, int m_novo){}

void hash_duplo_callback_redim(THEA* TH, int m_novo){
    TH->s = m_novo-1;
}

THEA* THEA_Criar(int m, FSONDAGEM f_sondagem){
    THEA* novo;
    int i;

    novo = malloc(sizeof(THEA));
    novo->TH = malloc(sizeof(ELEM) * m);
    novo->m = m;
    novo->n = 0;

    for(i = 0; i < m; i++)
        novo->TH[i].estado = E_LIVRE;

    novo->f_sondagem = f_sondagem;

    switch(f_sondagem){
        case FS_LINEAR:
            novo->hash = hash_linear;
            novo->callback_redim = dummy_callback_redim;
            break;
        case FS_QUADRATICA:
            novo->hash = hash_quadratica;
            novo->callback_redim = dummy_callback_redim;
            break;
        case FS_HASH_DUPLO:
            novo->hash = hash_duplo;
            novo->callback_redim = hash_duplo_callback_redim;
            novo->s = m-1;
    }


    return novo;
}

int THEA_Inserir(THEA *TH, int chave, int valor){

    int h, k, h_inicial;
    k = 0;

    if(TH->n+1 > TH->m / 2){
        int m_novo = prox_primo(TH->m * 2);

        //printf("redimensinada de %d para %d (n = %d)\n", TH->m, m_novo, TH->n);

        TH->callback_redim(TH, m_novo);

        THEA_Redimensionar(TH, m_novo);
    }

    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while(TH->TH[h].estado == E_OCUPADO){

        if(TH->TH[h].chave == chave){
            TH->n--;
            break;
        }

        k++;
        h = THEA_Hash(TH, chave, k);

        if(h == h_inicial)
            return -1;

    }

    TH->n++;
    TH->TH[h].chave = chave;
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;

    return h;
}

int THEA_Buscar(THEA *TH, int chave){
    int h, h_inicial, k;

    k = 0;
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while(TH->TH[h].estado != E_LIVRE){
        if((TH->TH[h].estado == E_OCUPADO)
            && (TH->TH[h].chave == chave)){
                return h;
        }

        k++;
        h = THEA_Hash(TH, chave, k);

        if(h_inicial == h){
            return -1;
        }

    }
    return -1;

}

void THEA_Remover(THEA* TH, int chave){
    int p;
    p = THEA_Buscar(TH, chave);
    if(p != -1){
        TH->TH[p].estado = E_APAGADO;
        TH->n--;
    }
}