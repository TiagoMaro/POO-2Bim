#include <iostream>

using namespace std;

class Calculadora {
public:
    // Sobrecarga 1: soma dois inteiros
    int somar(int a, int b) {
        cout << "Somando inteiros: ";
        return a + b;
    }

    // Sobrecarga 2: soma três inteiros
    int somar(int a, int b, int c) {
        cout << "Somando três inteiros: ";
        return a + b + c;
    }

    // Sobrecarga 3: soma dois doubles
    double somar(double a, double b) {
        cout << "Somando doubles: ";
        return a + b;
    }

    // Não é sobrecarga válida se apenas o tipo de retorno muda!
    // double somar(int a, int b) { ... } // ERRO: já existe um somar(int, int)
};

int main() {
    Calculadora calc;
    cout << calc.somar(5, 10) << endl;         // Chama somar(int, int)
    cout << calc.somar(1, 2, 3) << endl;       // Chama somar(int, int, int)
    cout << calc.somar(5.5, 10.2) << endl;     // Chama somar(double, double)
    return 0;
}