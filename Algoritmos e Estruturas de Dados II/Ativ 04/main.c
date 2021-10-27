#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//============================Auxiliares======================
void trocar(int* v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int min(int * v, int ini, int fim){
    int min = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] < v[min]){
            min = i;
        }
    }
    return min;
}

void print_vector(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

//============================Ex 01=======================

int SelectionMinK(int *v, int n, int k){
    if(k > n){
        int aux = min(v, 0, n-1);
        return v[aux];
        printf("ENTREEI\n");
    }

    int menor;
    for(int i = 0; i < n; i++){
        menor = min(v, i, n-1);
        trocar(v, i, menor);
        if(i == k-1) return v[i];
    }

}

//============================Ex 02=======================
int partition(int *v, int ini, int fim){
    int pivo = v[fim];
    int i = ini - 1;
    int j;
    for(j = ini; j < fim; j++){
        if(v[j] <= pivo){
            i++;
            trocar(v, i, j);
        }
    }
    trocar(v, i+1, fim);
    return i+1;
}

int QuickMinK(int *v, int e, int d, int k){
    if(e > d) return min(v, e, d);
    if(k > d-e+1) return min(v, e, d);

    int p = partition(v, e, d);
    if(p == k-1) return v[p];
    if(p < k-1) return QuickMinK(v, p+1, d, k);
    return QuickMinK(v, e, p-1, k);
}


//============================Ex 03=======================

unsigned int random_32bits(){
    unsigned int x;
    x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    return x;
}


void embaralhar(int *v, int ini, int fim){
    int i, j;

    for(i = fim-1; i > ini; i--){
    j = (random_32bits() % (i + 1));
    j = j <= ini? ini+1 : j;
    trocar(v, i, j);
    }

}

int* random_vector_unique_elems(int n, int seed){
    srand(seed);

    int* vetor = (int*) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        vetor[i] = i;
    }

    embaralhar(vetor, 0, n);

    return vetor;
}

//============================FUNÇÃO MAIN===================

int main(){

    int elementos = 1000000;
    int k = elementos;

    clock_t start;
    clock_t end;
    int* v = random_vector_unique_elems(elementos, 42);
    //print_vector(v, elementos);

    //TESTE SELECTION MIN K
    start = clock();
    int val_SelectionMinK = SelectionMinK(v, elementos, k);
    end = clock();

    printf("SelectionMinK(v, %d, 1) = %d\n", elementos, val_SelectionMinK);
    printf("Tempo: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    //TESTE QUICK MIN K
    start = clock();
    int val_QuickMinK = QuickMinK(v, 0, elementos-1, k);
    end = clock();

    printf("QuickMinK(v, 0, %d, 1) = %d\n", elementos-1, val_QuickMinK);
    printf("Tempo: %f\n", (double)(end - start) / CLOCKS_PER_SEC);



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