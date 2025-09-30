#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Funcionario {
    protected:
        string nome;
        int id;
    public:
        Funcionario(string _nome, int _id) : nome(_nome), id(_id) {}

        void exibirInfo() {
            cout << "Funcionario: " << nome << ", ID: " << id << endl;
        }

        virtual ~Funcionario() {
            cout << "Destrutor de Funcionario (" << nome << ") chamado." << endl;
        }
};

class Desenvolvedor : public Funcionario {
    private:
        int horasTrabalhadas;
        double taxaHora;
    public:
        Desenvolvedor(string _nome, int _id, int _horas, double _taxa) :
            Funcionario(_nome, _id), horasTrabalhadas(_horas), taxaHora(_taxa) {}

        double calcularSalario() {
            return horasTrabalhadas * taxaHora;
        }
};

class Gerente : public Funcionario {
    private:
        double salarioBase;
        double bonus;
    public:
        Gerente(string _nome, int _id, double _salario, double _bonus) :
            Funcionario(_nome, _id), salarioBase(_salario), bonus(_bonus) {}

        double calcularSalario() {
            return salarioBase + bonus;
        }
};

int main() {
    cout << "--- Exemplo de Classe Abstrata (Funcionario) ---" << endl;

    vector<Funcionario*> funcionarios;
    funcionarios.push_back(new Desenvolvedor("Alice", 101, 160, 50.0));
    funcionarios.push_back(new Gerente("Bob", 102, 8000.0, 1500.0));

    for (Funcionario* func : funcionarios) {
        func->exibirInfo();
        
        if (Desenvolvedor* dev = dynamic_cast<Desenvolvedor*>(func)) {
            cout << "Salário do Desenvolvedor: $" << dev->calcularSalario() << endl;
        } else if (Gerente* ger = dynamic_cast<Gerente*>(func)) {
            cout << "Salário do Gerente: $" << ger->calcularSalario() << endl;
        }
        cout << endl;
    }

    
    for (Funcionario* func : funcionarios) {
        delete func;
    }

    return 0;
}