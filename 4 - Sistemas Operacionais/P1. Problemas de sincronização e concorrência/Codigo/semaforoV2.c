
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define N_ALUNOS_SO 12
#define N_ALUNOS_COMPUTACAO 40

#define N_APRESENTADORES 3
#define N_PLATEIA 10



// Semaforos
sem_t sem_apresentadores_entrar;
sem_t sem_plateia_entrar;

sem_t sem_lista_entrada_assinada;
sem_t sem_plateia_lotada;

sem_t sem_fila_apresentacao;

sem_t sem_apresentacoes_concluidas;

sem_t sem_notas;

sem_t sem_apresentadores_sairam;

sem_t sem_plateia_assiste;

sem_t sem_plateia_vazia;

sem_t sem_plateia_sair;

// Variaveis globais
int quant_apresentadores_sala = 0;
int quant_plateia_sala = 0;

int quant_assinaturas_entrada = 0;

int quant_apresentacoes = 0;
int quant_total_apresentacoes = 0;

int quant_notas = 0;

int quant_assistindo = 0;

// Funcoes
void *professor(void *arg);
void *aluno_so(void *arg);
void *aluno_computacao(void *arg);


void *professor(void *arg){

    printf(" - Ola, turma, eu sou o professor Campiolo e hoje é o dia de suas apresentacoes. \n   %d pessoas assinem a lista e entrem na sala de apresentacoes.\n   Os outros alunos esperam do lado de fora.\n\n", N_APRESENTADORES);
    sleep(2);

    printf(">>> O professor entrou na sala\n\n");
    sleep(1);


    while(true){
        printf("-------------- RODADA --------------\n");
        // Libera entrada para os apresentadores
        for(int i = 0; i < N_APRESENTADORES; i++){
            sem_post(&sem_apresentadores_entrar);
        }

        // Libera entrada para a plateia
        for(int i = 0; i < N_PLATEIA; i++){
            sem_post(&sem_plateia_entrar);
        }

        // Espera todos os apresentadores assinarem a lista
        sem_wait(&sem_lista_entrada_assinada);

        // Espera a plateia entrar na sala
        sem_wait(&sem_plateia_lotada);

        // Inicia a apresentação
        printf(">>> O professor iniciou a apresentação\n\n");
        sem_post(&sem_fila_apresentacao);
        sem_post(&sem_plateia_assiste);
        sleep(1);

        // Espera todos os alunos apresentarem
        sem_wait(&sem_apresentacoes_concluidas);
        printf("\n>>> Professor encerra as apresentacoes!\n\n");
        sleep(1);
        sem_post(&sem_plateia_sair);

        // Atribui notas
        printf(">>> Professor esta atribuindo notas aos alunos de SO...\n\n");
        sleep(3);
        printf(">>> Professor terminou de atribuir notas aos alunos de SO!\n\n");
        sem_post(&sem_notas);

        // Espera a plateia sair
        sem_wait(&sem_plateia_vazia);

        // Espera os presentadores sairem
        sem_wait(&sem_apresentadores_sairam);


        // Reseta variaveis
        quant_assinaturas_entrada = 0;
        quant_plateia_sala = 0;
        quant_apresentacoes = 0;
        quant_notas = 0;
        quant_assistindo = 0;



        //break;
        if(quant_total_apresentacoes == N_ALUNOS_SO){
            break;
        }
    }
    printf("\n>>> O professor saiu da sala e fechou a porta.\n");
}



void *aluno_so(void *arg){
    int id = *(int*)arg;

    // Espera a permissao para entrar na sala
    sem_wait(&sem_apresentadores_entrar);
    printf(">>> Aluno_SO_%d entrou na sala\n", id);
    quant_apresentadores_sala++;

    // Assina a lista de entrada
    printf(">>> Aluno_SO_%d assinou a lista\n", id);
    quant_assinaturas_entrada++;

    if(quant_assinaturas_entrada == N_APRESENTADORES){
        printf(">>> APRESENTADORES PRONTOS <<<\n");
        sem_post(&sem_lista_entrada_assinada);
        sleep(1);
    }

    // Esperar na fila de apresentação
    sem_wait(&sem_fila_apresentacao);
    printf(">>> O aluno_SO_%d esta apresentando...\n", id);
    quant_apresentacoes++;
    sleep(1);

    if(quant_apresentacoes < N_APRESENTADORES){
        sem_post(&sem_fila_apresentacao);
    }
    printf(">>> O aluno_SO_%d terminou de apresentar\n", id);
    quant_total_apresentacoes++;

    // Fim das apresentacoes
    if(quant_apresentacoes == N_APRESENTADORES){
        printf(">>> TODOS OS ALUNOS DE SO TERMINARAM DE APRESENTAR\n");
        sem_post(&sem_apresentacoes_concluidas);
    }

    // Esperam as notas serem distribuidas
    sem_wait(&sem_notas);
    quant_notas++;
    printf(">>> Nota recebida pelo aluno_SO_%d\n", id);
    sleep(1);
    if(quant_notas < N_APRESENTADORES){
        sem_post(&sem_notas);
    }

    // Assinam a lista de saida
    printf(">>> Aluno_SO_%d assinou a lista de saida e saiu!\n", id);
    quant_apresentadores_sala--;
    if(quant_apresentadores_sala == 0){
        printf(">>> TODOS OS APRESENTADORES SAIRAM DA SALA\n");
        sem_post(&sem_apresentadores_sairam);
    }

}





void *aluno_computacao(void *arg){
    int id = *(int*)arg;

    // Espera a permissao para entrar na sala
    sem_wait(&sem_plateia_entrar);
    printf(">>> Aluno_COMPUTACAO_%d entrou na sala\n", id);
    quant_plateia_sala++;

    if(quant_plateia_sala == N_PLATEIA){
        printf(">>> PLATEIA PRONTA <<<\n");
        sem_post(&sem_plateia_lotada);
        sleep(1);
    }

    // Espera o inicio das apresentações
    sem_wait(&sem_plateia_assiste);

    // Assistem as apresentações
    quant_assistindo++;

    // Os alunos tem 20% de chance de ir embora durante a apresentação
    
    if(rand() % 100 < 20){
        printf(">>> Aluno_COMPUTACAO_%d saiu da sala\n", id);
        quant_plateia_sala--;
        sem_post(&sem_plateia_assiste);
        return NULL;
    }


    if(quant_assistindo < N_PLATEIA){
        sem_post(&sem_plateia_assiste);
    }

    // Espera o fim das apresentações
    sem_wait(&sem_plateia_sair);
    sleep(1);
    quant_plateia_sala--;
    printf(">>> O aluno_COMPUTACAO_%d saiu da sala\n", id);

    if(quant_plateia_sala == 0){
        printf(">>> PLATEIA VAZIA!!!\n");
        sem_post(&sem_plateia_vazia);
    } else{
        sem_post(&sem_plateia_sair);
    }

    return NULL;
}





int main(){
    // Inicialização dos semaforos
    sem_init(&sem_apresentadores_entrar, 0, 0);
    sem_init(&sem_plateia_entrar, 0, 0);

    sem_init(&sem_lista_entrada_assinada, 0, 0);
    sem_init(&sem_plateia_lotada, 0, 0);

    sem_init(&sem_fila_apresentacao, 0, 0);

    sem_init(&sem_apresentacoes_concluidas, 0, 0);

    sem_init(&sem_notas, 0, 0);

    sem_init(&sem_apresentadores_sairam, 0, 0);

    sem_init(&sem_plateia_assiste, 0, 0);

    sem_init(&sem_plateia_sair, 0, 0);

    sem_init(&sem_plateia_vazia, 0, 0);

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
        id_aluno_so = malloc(sizeof(int));
        *id_aluno_so = i;
        pthread_create(&aluno_so_thread[i], NULL, aluno_so, (void*) id_aluno_so);
    }

    for(i = 0; i < N_ALUNOS_COMPUTACAO; i++){
        id_aluno_computacao = malloc(sizeof(int));
        *id_aluno_computacao = i;
        pthread_create(&aluno_computacao_thread[i], NULL, aluno_computacao, (void*) id_aluno_computacao);
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