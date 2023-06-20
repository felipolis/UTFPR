#include <iostream>

using namespace std;

class ListSeq {

public:
    int size = 0;   // controla as ocupações
    int capacity;   // define a capacidade da lista
    int* data;      // endereço (aponta) do vetor da lista
    // construtor que cria a instância da lista
    ListSeq(int _capacity);
    // Libera a memória alocada para o vetor
    void destroy();
    // realoca vetor 
    bool resize();
    // imprime conteúdo da lista
    bool print();
    // retorna posição do elemento ou -1
    int find(int elem);
    // obtém o elemento na posição passada
    int get(int pos);
    // lista vazia?
    bool isEmpty();
    // lista cheia?
    bool isFull();
    // insere elemento no final
    bool add(int elem);
    // remove elemento do final
    bool remove();
    // insere elemento na posição especificada
    void insert(int elem, int pos);
    // remove elemento na posição especificada
    bool removeAt(int pos);
    // insere elemento em ordem crescente
    bool addSorted(int elem);
};
