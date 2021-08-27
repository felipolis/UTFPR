#include "tad_timer.h"

/*******************************************************************
*   ESPECIFICACAO DA STRUCT
*******************************************************************/

struct timer{
    clock_t inicio;
    clock_t fim;
    clock_t total;
};


/*******************************************************************
*   IMPLEMENTACAO
*******************************************************************/

Timer* timer_criar(){
    Timer* t = (Timer*) malloc(sizeof(Timer));
    t->inicio = -1;
    t->fim = -1;
    t->total = -1;
    return t;
}

void timer_desalocar(Timer** t){
    free(*t);
    *t = NULL;
}

void timer_start(Timer* t){
    t->inicio = clock();
}

void timer_stop(Timer* t){
    (t->fim) = clock();
}

void timer_reset(Timer* t){
    t->inicio = -1;
    t->fim = -1;
    t->total = -1;
}

float timer_resultado(Timer* t){
    return (t->fim - t->inicio)/CLOCKS_PER_SEC;
}