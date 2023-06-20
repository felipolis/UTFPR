#include <iostream>

using namespace std;


template <typename T>
T maior(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int i = 36;
    int j = 2;
    // instância implícita
    cout << "maior(i, j): " << maior(i, j) << endl;

    float f1 = 36.11;
    float f2 = 2.11;
    // necessário instância explícita
    cout << "maior(f1, f2): " << maior<double>(f1, f2) << endl;

    string s1 = "Rodrigo";
    string s2 = "Bento";
    cout << "maior(s1, s2): " << maior(s1, s2) << endl;
}