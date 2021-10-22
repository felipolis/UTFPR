#include "abb.h"
#include "arn.h"
#include <time.h>
#include <math.h>


//========================================FUNÇÕES AUXILIARES===================================

unsigned int random_32bits(){
    unsigned int x;
   
    x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;

    return x;
}

bool existe_valor(int* vetor, int tam, int valor){
    for(int i = 0; i < tam; i++){
        if(vetor[i] == valor) return true;
    }
    return false;
}

int* criar_vetor_aleatorio(int tam, int max, int seed){
    srand(seed);
    int* vetor = (int*) calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){

        do{
        vetor[i] = random_32bits() % max;
        }while(existe_valor(vetor, i, vetor[i]));
        
    }

    return vetor;
}

int* criar_vetor(int tam, int escolha){ //escolha = 0 (crescente); escolha = 1 (decrescente)
    int* vet = (int*) calloc(tam, sizeof(int));

    if(escolha == 0){
        for(int i = 0; i < tam; i++){
            vet[i] = i;
        }
    } else{
        for(int i = tam-1; i >= 0; i--){
            vet[i] = i;
        }
    }

    return vet;
}


//========================================FUNÇÕES TESTES===================================

void c_ABB(int quant){

    printf("====== ABB: N inteiros em ordem decrescente =======\n");
    clock_t start;
    clock_t end;
    double tempo;

    int alt;

    int n = quant;
    int* v = criar_vetor(n, 1); 

    start = clock();
    alt = ABB_Sort(v, n);
    end = clock();

    tempo = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", tempo);
    printf("Altura da arvore: %d\n", alt);

    printf("\n");
}

void c_ARN(int quant){
    printf("====== ARN: N inteiros em ordem decrescente =======\n");
    clock_t start;
    clock_t end;
    double tempo;

    int alt;

    int n = quant;
    int* v = criar_vetor(n, 1); 

    start = clock();
    alt = ARN_Sort(v, n);
    end = clock();

    tempo = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f\n", tempo);
    printf("Altura da arvore: %d\n", alt);

    printf("\n");
}

void d_ABB(int quant){

    printf("====== ABB: N inteiros gerados aleatoriamente =======\n");
    clock_t start1;
    clock_t start2;
    clock_t start3;
    clock_t start4;
    clock_t start5;
    clock_t start6;
    clock_t start7;
    clock_t start8;
    clock_t start9;
    clock_t start10;
    clock_t end1;
    clock_t end2;
    clock_t end3;
    clock_t end4;
    clock_t end5;
    clock_t end6;
    clock_t end7;
    clock_t end8;
    clock_t end9;
    clock_t end10;
    double tempo1;
    double tempo2;
    double tempo3;
    double tempo4;
    double tempo5;
    double tempo6;
    double tempo7;
    double tempo8;
    double tempo9;
    double tempo10;

    float MA;

    int n = quant;
    int* v1 = criar_vetor_aleatorio(n, 10*n, 10);
    int* v2 = criar_vetor_aleatorio(n, 10*n, 20);
    int* v3 = criar_vetor_aleatorio(n, 10*n, 30);
    int* v4 = criar_vetor_aleatorio(n, 10*n, 40);
    int* v5 = criar_vetor_aleatorio(n, 10*n, 50);
    int* v6 = criar_vetor_aleatorio(n, 10*n, 60);
    int* v7 = criar_vetor_aleatorio(n, 10*n, 70);
    int* v8 = criar_vetor_aleatorio(n, 10*n, 80);
    int* v9 = criar_vetor_aleatorio(n, 10*n, 90);
    int* v10 = criar_vetor_aleatorio(n, 10*n, 100);

    //Primeiro
    start1 = clock();
    int alt1 = ABB_Sort(v1, n);
    end1 = clock();
    tempo1 = (double)(end1 - start1)/CLOCKS_PER_SEC;

    //Segundo
    start2 = clock();
    int alt2 = ABB_Sort(v2, n);
    end2 = clock();
    tempo2 = (double)(end2 - start2)/CLOCKS_PER_SEC;

    //Terceiro
    start3 = clock();
    int alt3 = ABB_Sort(v3, n);
    end3 = clock();
    tempo3 = (double)(end3 - start3)/CLOCKS_PER_SEC;

    //Quarto
    start4 = clock();
    int alt4 = ABB_Sort(v4, n);
    end4 = clock();
    tempo4 = (double)(end4 - start4)/CLOCKS_PER_SEC;

    //Quinto
    start5 = clock();
    int alt5 = ABB_Sort(v5, n);
    end5 = clock();
    tempo5 = (double)(end5 - start5)/CLOCKS_PER_SEC;

    //Sexto
    start6 = clock();
    int alt6 = ABB_Sort(v6, n);
    end6 = clock();
    tempo6 = (double)(end6 - start6)/CLOCKS_PER_SEC;

    //Setimo
    start7 = clock();
    int alt7 = ABB_Sort(v7, n);
    end7 = clock();
    tempo7 = (double)(end7 - start7)/CLOCKS_PER_SEC;

    //Oitavo
    start8 = clock();
    int alt8 = ABB_Sort(v8, n);
    end8 = clock();
    tempo8 = (double)(end8 - start8)/CLOCKS_PER_SEC;

    //Nono
    start9 = clock();
    int alt9 = ABB_Sort(v9, n);
    end9 = clock();
    tempo9 = (double)(end9 - start9)/CLOCKS_PER_SEC;

    //Decimo
    start10 = clock();
    int alt10 = ABB_Sort(v10, n);
    end10 = clock();
    tempo10 = (double)(end10 - start10)/CLOCKS_PER_SEC;

    double TM = (tempo1 + tempo2 + tempo3 + tempo4 + tempo5 + tempo6 + tempo7 + tempo8 + tempo9 + tempo10)/10;

    double DP = sqrt(
        pow(tempo1 - TM, 2) + pow(tempo2 - TM, 2) + pow(tempo3 - TM, 2) + pow(tempo4 - TM, 2) +
        pow(tempo5 - TM, 2) + pow(tempo6 - TM, 2) + pow(tempo7 - TM, 2) + pow(tempo8 - TM, 2) +
        pow(tempo9 - TM, 2) + pow(tempo10 - TM, 2)
    )/10;

    MA = (alt1 + alt2 + alt3 + alt4 + alt5 + alt6 + alt7 + alt8 + alt9 + alt10)/10;

    printf("Tempo medio: %f\n", TM);
    printf("Desvio Padrao: %f\n", DP);
    printf("Altura media: %f\n", MA);
    printf("\n");

}

void d_ARN(int quant){

    printf("====== ARN: N inteiros gerados aleatoriamente =======\n");
    clock_t start1;
    clock_t start2;
    clock_t start3;
    clock_t start4;
    clock_t start5;
    clock_t start6;
    clock_t start7;
    clock_t start8;
    clock_t start9;
    clock_t start10;
    clock_t end1;
    clock_t end2;
    clock_t end3;
    clock_t end4;
    clock_t end5;
    clock_t end6;
    clock_t end7;
    clock_t end8;
    clock_t end9;
    clock_t end10;
    double tempo1;
    double tempo2;
    double tempo3;
    double tempo4;
    double tempo5;
    double tempo6;
    double tempo7;
    double tempo8;
    double tempo9;
    double tempo10;

    float MA;

    int n = quant;
    int* v1 = criar_vetor_aleatorio(n, 10*n, 10);
    int* v2 = criar_vetor_aleatorio(n, 10*n, 20);
    int* v3 = criar_vetor_aleatorio(n, 10*n, 30);
    int* v4 = criar_vetor_aleatorio(n, 10*n, 40);
    int* v5 = criar_vetor_aleatorio(n, 10*n, 50);
    int* v6 = criar_vetor_aleatorio(n, 10*n, 60);
    int* v7 = criar_vetor_aleatorio(n, 10*n, 70);
    int* v8 = criar_vetor_aleatorio(n, 10*n, 80);
    int* v9 = criar_vetor_aleatorio(n, 10*n, 90);
    int* v10 = criar_vetor_aleatorio(n, 10*n, 100);

    //Primeiro
    start1 = clock();
    int alt1 = ARN_Sort(v1, n);
    end1 = clock();
    tempo1 = (double)(end1 - start1)/CLOCKS_PER_SEC;

    //Segundo
    start2 = clock();
    int alt2 = ARN_Sort(v2, n);
    end2 = clock();
    tempo2 = (double)(end2 - start2)/CLOCKS_PER_SEC;

    //Terceiro
    start3 = clock();
    int alt3 = ARN_Sort(v3, n);
    end3 = clock();
    tempo3 = (double)(end3 - start3)/CLOCKS_PER_SEC;

    //Quarto
    start4 = clock();
    int alt4 = ARN_Sort(v4, n);
    end4 = clock();
    tempo4 = (double)(end4 - start4)/CLOCKS_PER_SEC;

    //Quinto
    start5 = clock();
    int alt5 = ARN_Sort(v5, n);
    end5 = clock();
    tempo5 = (double)(end5 - start5)/CLOCKS_PER_SEC;

    //Sexto
    start6 = clock();
    int alt6 = ARN_Sort(v6, n);
    end6 = clock();
    tempo6 = (double)(end6 - start6)/CLOCKS_PER_SEC;

    //Setimo
    start7 = clock();
    int alt7 = ARN_Sort(v7, n);
    end7 = clock();
    tempo7 = (double)(end7 - start7)/CLOCKS_PER_SEC;

    //Oitavo
    start8 = clock();
    int alt8 = ARN_Sort(v8, n);
    end8 = clock();
    tempo8 = (double)(end8 - start8)/CLOCKS_PER_SEC;

    //Nono
    start9 = clock();
    int alt9 = ARN_Sort(v9, n);
    end9 = clock();
    tempo9 = (double)(end9 - start9)/CLOCKS_PER_SEC;

    //Decimo
    start10 = clock();
    int alt10 = ARN_Sort(v10, n);
    end10 = clock();
    tempo10 = (double)(end10 - start10)/CLOCKS_PER_SEC;

    double TM = (tempo1 + tempo2 + tempo3 + tempo4 + tempo5 + tempo6 + tempo7 + tempo8 + tempo9 + tempo10)/10;

    double DP = sqrt(
        pow(tempo1 - TM, 2) + pow(tempo2 - TM, 2) + pow(tempo3 - TM, 2) + pow(tempo4 - TM, 2) +
        pow(tempo5 - TM, 2) + pow(tempo6 - TM, 2) + pow(tempo7 - TM, 2) + pow(tempo8 - TM, 2) +
        pow(tempo9 - TM, 2) + pow(tempo10 - TM, 2)
    )/10;

    MA = (alt1 + alt2 + alt3 + alt4 + alt5 + alt6 + alt7 + alt8 + alt9 + alt10)/10;

    printf("Tempo medio: %f\n", TM);
    printf("Desvio Padrao: %f\n", DP);
    printf("Altura media: %f\n", MA);
    printf("\n");

}




//========================================FUNÇÃO MAIN==========================================
int main(){

    //ABB: Item C
    c_ABB(1000);

    //ARN: Item C
    c_ARN(1000);

    //ABB: Item D
    d_ABB(1000);

    //ARN: Item D
    d_ARN(1000);

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