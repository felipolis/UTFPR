#include <iostream>
#include <string>

using namespace std;

class Pessoa {

private:
    short int idade;
    string nome;

public:
    Pessoa(string nome_, short int idade_) {
        nome = nome_;
        idade = idade_;
    }
    Pessoa() {}
    Pessoa operator+(Pessoa segundo) {
        Pessoa retorna;
        retorna.idade = idade + segundo.idade;
        retorna.nome = nome + segundo.nome;
        return retorna;
    }
    void imprime() {
        cout << nome << " : " << idade << endl;
    }
};

int main() {
    Pessoa a("Ana ", 12), b("Maria", 30), c;
    c = a + b;
    c.imprime();
}