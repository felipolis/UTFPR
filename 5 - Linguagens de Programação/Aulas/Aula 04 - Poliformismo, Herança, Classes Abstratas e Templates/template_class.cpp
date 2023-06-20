#include <iostream>
using namespace std;

template <class T>
class Pares {
    T a, b;
    public:
        Pares (T primeiro, T segundo) {
            a = primeiro;
            b = segundo;
        }
        T getmax ();
};

template <class T>
T Pares<T>::getmax() {
    T res;
    res = a > b? a : b;
    return res;
}

int main () {
    Pares <int> obj (25, 35);
    cout << obj.getmax() << endl;
    return 0;
}