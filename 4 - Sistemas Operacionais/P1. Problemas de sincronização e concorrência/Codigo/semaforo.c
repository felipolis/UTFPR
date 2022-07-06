/* 
    DATA:
        - 07/05/2022

    AUTORES:
        - Felipe Archanjo da Cunha Mendes,  RA: 2252740
        - Pamella Lissa Sato Tamura,        RA: 2254107

    DESCRIÇÃO:
        - Este trabalho simula rodadas de apresentação de palestras de alunos de SO para alunos do curso de ciencia da computação em uma sala fechada

        - Definindo-se N alunos de SO que farão a apresentação, apenas parte desse N poderão entrar na sala para apresentar as palestras em ordem de chegada.

        - Aos alunos que entram (N_APRESENTADORES por vez), ha uma fila para assinar a lista de entrada e logo após uma outra fila para apresentar.

        - Ao mesmo tempo, os alunos de computação (plateia) vai entrando no recinto.

        - O professor Campiolo espera que todos os alunos de SO (apresentadores) e de computação (plateia) entrem na sala.

        - Ao notar que todos estao preparados, o professor Campiolo inicia a primeira leva de apresentações.

        - Cada apresentador apresenta na sua vez, sem interromper o outro.

        - A plateia composta por alunos de computação pode sair da sala a hora que quiser, sendo que a probabilidade de um deles sair foi definido como sendo de 20%.

        - Após a primeira leva de apresentações terminar, o professor Campiolo entrega as notas de cada apresentador.

        - Nesse meio tempo, a plateia ja pode ir se retirando.

        - Ao receber sua nota, cada apresentador assina a lista de saida e sai da sala.

        - Após a sala ficar vazia, o professor Campiolo abre a porta para que novos apresentadores e plateia entrem na sala.

 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Defines
#define N_ALUNOS_SO 12
#define N_APRESENTADORES 3

#define N_ALUNOS_COMPUTACAO 40
#define N_PLATEIA 10

// Semaforos
sem_t sem_assinar_lista_entrada;
sem_t sem_lista_entrada_assinada;
sem_t sem_iniciar_apresentacao;
sem_t sem_apresentacoes_concluidas;
sem_t sem_notas;
sem_t sem_assinar_lista_saida;
sem_t sem_apresentadores_sairam;
sem_t sem_plateia_lotada;
sem_t sem_plateia_assiste;
sem_t sem_plateia_saindo_final_apresentacao;
sem_t sem_plateia_vazia;
sem_t sem_apresentadores_entrar;
sem_t sem_plateia_entrar;

// Variaveis globais
int quant_apresentadores_sala = 0;
int quant_assinaturas_entrada = 0;
int quant_plateia_sala = 0;
int quant_apresentacoes = 0;
int quant_apresentacoes_total = 0;
int quant_notas = 0;
int quant_assistindo = 0;


// Instancias de funcoes
void *professor(void *arg);
void *aluno_so(void *arg);
void *aluno_computacao(void *arg);

// Funcoes
void *professor(void *arg){

    printf(" - Ola, turma, eu sou o professor Campiolo e hoje é o dia de suas apresentacoes. \n   %d pessoas assinem a lista e entrem na sala de apresentacoes.\n   Os outros alunos esperam do lado de fora.\n\n", N_APRESENTADORES);
    sleep(2);

    printf(">>> O professor entrou na sala\n\n");
    sleep(1);

    while(true){

        printf("\n\n-------------- NOVA APRESENTACAO --------------\n\n");

        // Liberar a porta de entrada para os apresentadores e plateia
        sem_post(&sem_apresentadores_entrar);
        sem_post(&sem_plateia_entrar);

        // Esperar que todos os apresentadores entrem e assinem a lista de entrada
        sem_wait(&sem_lista_entrada_assinada);

        // Esperar a plateia ficar lotada
        sem_wait(&sem_plateia_lotada);

        // Inicia a apresentação
        printf("\n>>> O professor iniciou a apresentação\n\n");
        sem_post(&sem_iniciar_apresentacao);
        sleep(1);
        sem_post(&sem_plateia_assiste);

        // Espera todos os alunos apresentarem
        sem_wait(&sem_apresentacoes_concluidas);
        printf("\n>>> Professor encerra as apresentacoes!\n\n");
        sleep(1);
        sem_post(&sem_plateia_saindo_final_apresentacao);

        // Atribuição de notas
        printf(">>> Professor esta atribuindo notas aos alunos de SO...\n\n");
        sleep(3);
        printf(">>> Professor terminou de atribuir notas aos alunos de SO!\n\n");
        sem_post(&sem_notas);

        // Espera a plateia sair
        sem_wait(&sem_plateia_vazia);

        // Espera que todos os apresentadores saiam
        sem_wait(&sem_apresentadores_sairam);

        // Resetar variaveis
        quant_apresentadores_sala = 0;
        quant_assinaturas_entrada = 0;
        quant_plateia_sala = 0;
        quant_apresentacoes = 0;
        quant_notas = 0;
        quant_assistindo = 0;

        // Verificar se acabaram todas as apresentacoes do dia
        if(quant_apresentacoes_total == N_ALUNOS_SO){
            break;
        }

        sleep(3);
    }

    printf("\n>>> O professor saiu da sala e fechou a porta.\n");

}

void *aluno_so(void *arg){
    int id = *(int*)arg;


    // Porta de entrada à sala de apresentações (1 por vez)
    sem_wait(&sem_apresentadores_entrar);

    printf(">>> Aluno_SO_%d entrou na sala\n", id);
    quant_apresentadores_sala++;
    sleep(1);

    if(quant_apresentadores_sala < N_APRESENTADORES){
        sem_post(&sem_apresentadores_entrar);
    }

    // Assina a lista de entrada e espera na fila de apresentações (1 por vez)
    sem_wait(&sem_assinar_lista_entrada);

    printf(">>> Aluno_SO_%d assinou a lista de entrada\n", id);
    quant_assinaturas_entrada++;
    sleep(1);

    if(quant_assinaturas_entrada == N_APRESENTADORES){                                  // Se for o ultimo a assinar
        printf(">>> APRESENTADORES PRONTOS <<<\n");
        sem_post(&sem_lista_entrada_assinada);
    }

    sem_post(&sem_assinar_lista_entrada);

    // Fila de apresentação (1 por vez)
    sem_wait(&sem_iniciar_apresentacao);

    printf(">>> O aluno_SO_%d comecou a apresentar...\n", id);
    quant_apresentacoes++;
    quant_apresentacoes_total++;
    sleep(3);
    printf(">>> O aluno_SO_%d terminou de apresentar\n", id);
    sleep(1);

    if(quant_apresentacoes == N_APRESENTADORES){
        printf(">>> TODOS OS ALUNOS DE SO TERMINARAM DE APRESENTAR\n");
        sleep(1);
        sem_post(&sem_apresentacoes_concluidas);    // Avisa ao professor que as apresentacoes foram concluidas
    } else{
        sem_post(&sem_iniciar_apresentacao);
    }

    // Espera as notas serem distribuidas (1 por vez)
    sem_wait(&sem_notas);

    printf(">>> O aluno_SO_%d recebeu sua nota\n", id);
    quant_notas++;
    sleep(1);

    if(quant_notas == N_APRESENTADORES){
        //printf(">>> TODOS OS ALUNOS DE SO RECEBERAM SUAS NOTAS\n");
        sleep(1);
    } else{
        sem_post(&sem_notas);
    }

    // Assina a lista de saida (1 por vez)
    sem_wait(&sem_assinar_lista_saida);

    printf(">>> Aluno_SO_%d assinou a lista de saida e saiu\n", id);
    quant_apresentadores_sala--;
    sleep(1);
    if(quant_apresentadores_sala == 0){
        printf(">>> TODOS OS APRESENTADORES SAIRAM DA SALA\n");
        sem_post(&sem_apresentadores_sairam);
    }

    sem_post(&sem_assinar_lista_saida);

    return NULL;

}

void *aluno_computacao(void *arg){
    int id = *(int*)arg;

    // Porta de entrada à sala de apresentações (1 por vez)
    sem_wait(&sem_plateia_entrar);

    printf(">>> Aluno_COMPUTACAO_%d entrou na sala\n", id);
    quant_plateia_sala++;

    if(quant_plateia_sala == N_PLATEIA){
        printf(">>> PLATEIA PRONTA <<<\n");
        sem_post(&sem_plateia_lotada);
        sleep(1);
    }

    if(quant_plateia_sala < N_PLATEIA){
        sem_post(&sem_plateia_entrar);
    }

    // Assiste a apresentação (N_PLATEIA por vez)
    sem_wait(&sem_plateia_assiste);
    quant_assistindo++;

    // Ou ele sai durante a apresentação
    if(rand() % 100 < 20){
        printf(">>> Aluno_COMPUTACAO_%d saiu da sala\n", id);
        quant_plateia_sala--;
        sem_post(&sem_plateia_assiste);
        return NULL;
    }

    // Ou ele termina de assitir a apresentação
    if(quant_assistindo < N_PLATEIA){
        sem_post(&sem_plateia_assiste);
    }

    sem_wait(&sem_plateia_saindo_final_apresentacao);
    sleep(1);
    quant_plateia_sala--;
    printf(">>> O aluno_COMPUTACAO_%d saiu da sala\n", id);

    if(quant_plateia_sala == 0){
        printf(">>> PLATEIA VAZIA!!!\n");
        sem_post(&sem_plateia_vazia);
    } else{
        sem_post(&sem_plateia_saindo_final_apresentacao);
    }

    return NULL;


}


// Função principal
int main(){

    // Inicialização dos semaforos
    sem_init(&sem_assinar_lista_entrada, 0, 1);
    sem_init(&sem_lista_entrada_assinada, 0, 0);
    sem_init(&sem_iniciar_apresentacao, 0, 0);
    sem_init(&sem_apresentacoes_concluidas, 0, 0);
    sem_init(&sem_notas, 0, 0);
    sem_init(&sem_assinar_lista_saida, 0, 1);
    sem_init(&sem_apresentadores_sairam, 0, 0);
    sem_init(&sem_plateia_lotada, 0, 0);
    sem_init(&sem_plateia_assiste, 0, 0);
    sem_init(&sem_plateia_saindo_final_apresentacao, 0, 0);
    sem_init(&sem_plateia_vazia, 0, 0);
    sem_init(&sem_apresentadores_entrar, 0, 0);
    sem_init(&sem_plateia_entrar, 0, 0);

    // Criação das threads
    pthread_t professor_thread;
    pthread_t aluno_so_thread[N_ALUNOS_SO];
    pthread_t aluno_computacao_thread[N_ALUNOS_COMPUTACAO];

    // Cria argumentos para as threads
    int i;
    int *id_aluno_so;
    int *id_aluno_computacao;

    // Cria as threads
    pthread_create(&professor_thread, NULL, professor, NULL);

    for(i = 0; i < N_ALUNOS_SO; i++){
        id_aluno_so = (int*)malloc(sizeof(int));
        *id_aluno_so = i;
        pthread_create(&aluno_so_thread[i], NULL, aluno_so, id_aluno_so);
    }

    for(i = 0; i < N_ALUNOS_COMPUTACAO; i++){
        id_aluno_computacao = (int*)malloc(sizeof(int));
        *id_aluno_computacao = i;
        pthread_create(&aluno_computacao_thread[i], NULL, aluno_computacao, id_aluno_computacao);
    }


    // Espera pelas threads
    pthread_join(professor_thread, NULL);

    for(i = 0; i < N_ALUNOS_SO; i++){
        pthread_join(aluno_so_thread[i], NULL);
    }

    for(i = 0; i < N_ALUNOS_COMPUTACAO; i++){
        pthread_join(aluno_computacao_thread[i], NULL);
    }

    return 0;
}