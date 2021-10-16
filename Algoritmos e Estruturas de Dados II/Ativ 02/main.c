#include "abb.h"

int main(){

    //TESTE 01
    printf("============TESTE 01============\n\n");

    ABB* arvore1 = ABB_Criar(70);
    ABB_Inserir(&arvore1, 39);
    ABB_Inserir(&arvore1, 88);
    printf("Itens adicionados:\n");
    ABB_Imprimir(arvore1, 0, 'r');

    printf("Item removido: %d\n", 70);
    ABB_Remover(&arvore1, 70);
    ABB_Imprimir(arvore1, 0, 'r');

    printf("\n");
    printf("============TESTE 02============\n\n");

    ABB* arvore2 = ABB_Criar(10);
    ABB_Inserir(&arvore2, 4);
    ABB_Inserir(&arvore2, 20);
    ABB_Inserir(&arvore2, 6);
    ABB_Inserir(&arvore2, 2);
    ABB_Inserir(&arvore2, 3);
    ABB_Inserir(&arvore2, 5);
    ABB_Inserir(&arvore2, 7);
    printf("Itens adicionados:\n");
    ABB_Imprimir(arvore2, 0, 'r');

    printf("Item removido: %d\n", 10);
    ABB_Remover(&arvore2, 10);
    ABB_Imprimir(arvore2, 0, 'r');

    printf("Item removido: %d\n", 4);
    ABB_Remover(&arvore2, 4);
    ABB_Imprimir(arvore2, 0, 'r');

    printf("Item removido: %d\n", 5);
    ABB_Remover(&arvore2, 5);
    ABB_Imprimir(arvore2, 0, 'r');

    printf("\n");
    printf("============TESTE 03============\n\n");

    ABB* arvore3 = ABB_Criar(30);
    ABB_Inserir(&arvore3, 50);
    ABB_Inserir(&arvore3, 40);
    ABB_Inserir(&arvore3, 47);
    ABB_Inserir(&arvore3, 15);
    ABB_Inserir(&arvore3, 20);
    ABB_Inserir(&arvore3, 25);
    ABB_Inserir(&arvore3, 17);
    ABB_Inserir(&arvore3, 19);
    ABB_Inserir(&arvore3, 4);
    ABB_Inserir(&arvore3, 7);
    ABB_Inserir(&arvore3, 0);
    printf("Itens adicionados:\n");
    ABB_Imprimir(arvore3, 0, 'r');

    printf("Item removido: %d\n", 0);
    ABB_Remover(&arvore3, 0);
    ABB_Imprimir(arvore3, 0, 'r');

    printf("Item removido: %d\n", 30);
    ABB_Remover(&arvore3, 4);
    ABB_Imprimir(arvore3, 0, 'r');

    printf("Item removido: %d\n", 15);
    ABB_Remover(&arvore3, 15);
    ABB_Imprimir(arvore3, 0, 'r');

    printf("Item removido: %d\n", 20);
    ABB_Remover(&arvore3, 20);
    ABB_Imprimir(arvore3, 0, 'r');

    printf("\n");
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