#include "tad_timer.h"
#include <stdlib.h>
#include <stdio.h>

#include <time.h>



/*******************************************************************
*  DADOS
*******************************************************************/
struct timer{
    clock_t inicio;
    clock_t fim;
    clock_t resultado;
};


/*******************************************************************
*  OPERACOES
*******************************************************************/


/**
 * Cria um timer
 */
Timer* timer_criar(){
    printf("Usando tad_timer2.c");
    Timer* t = (Timer*) malloc(sizeof(Timer));
    timer_reset(t);

    return t;
}

/**
 * Destroi um timer
 */
void timer_desalocar(Timer** t){
    free(*t);
    *t = NULL;
}


/**
 * Inicia o timer
 */
void timer_start(Timer* t){
    t->inicio = clock();
}

/**
 * Para o timer
 */
void timer_stop(Timer* t){
    t->fim = clock();
}

/**
 * Reinicia o timer
 */
void timer_reset(Timer* t){
    t->inicio = 0;
    t->fim = 0;
}

/**
 * Devolve o resultado.
 * Caso o timer ainda não tenha finalizado devolve -1
 */
float timer_resultado(Timer* t){
    if(t->inicio == 0) return -1;
    if(t->fim == 0) return -1;

    t->resultado = t->fim - t->inicio;
    return (float)(t->resultado/CLOCKS_PER_SEC);

}
