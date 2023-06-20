#include <iostream>
#include <forward_list>
using namespace std;


void imprime_list(forward_list<int> l) {
    for (auto e : l) {
        cout << e << " ";
    }
    cout << endl;
}

bool desc_order(int elem, int next) {
   return elem > next;
}

int main() {
    forward_list<int> list = {5, 4, 3, 2, 3, 4, 1, 7, 5, 5};

    list.sort();
    imprime_list(list);

    list.sort(desc_order);
    imprime_list(list);
}