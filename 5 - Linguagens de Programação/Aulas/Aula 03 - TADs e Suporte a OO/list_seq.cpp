#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;


// construtor que cria a instância da lista
ListSeq::ListSeq(int _capacity) {
    data = new int[_capacity];
    capacity = _capacity;
}

// Libera a memória alocada para o vetor
void ListSeq::destroy() {
    delete[] data;
}

// realoca vetor 
bool ListSeq::resize() {
    if (size == capacity) {
        capacity++;
        int* new_array = new int[capacity];
        for (int i=0; i<size; i++)
            new_array[i] = data[i];
        destroy();
        data = new_array;
        return true;
    } else { return false; }
}

// imprime conteúdo da lista
bool ListSeq::print() {
    if (! isEmpty()) {
        for (int i=0; i<size; i++)
            cout << data[i] << " ";
        cout << endl;
        return true;
    } else { return false; }
}

// retorna posição do elemento ou -1
int ListSeq::find(int elem) {
    return 1;
}

// obtém o elemento na posição argumentada
int ListSeq::get(int pos) {
    return 1;
}

// lista vazia?
bool ListSeq::isEmpty() {
    return false;
}

// lista cheia?
bool ListSeq::isFull() {
    return false;
}

// insere elemento no final
bool ListSeq::add(int elem) {
    if (size < capacity) {
        data[size++] = elem;
        return true;
    } else { return false; }
}

// remove elemento do final
bool ListSeq::remove() {
    return true;
}

// insere elemento na posição especificada
void ListSeq::insert(int elem, int pos) {}

// remove elemento na posição especificada
bool ListSeq::removeAt(int pos) {
    return true;
}

// insere elemento em ordem crescente
bool ListSeq::addSorted(int elem) {
    return true;
}
