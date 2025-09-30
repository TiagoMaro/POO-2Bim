#include <iostream>
#include <string>

using namespace std;

class contaBancaria
{
protected:
    double saldo;
    string numeroConta;

public:
    contaBancaria(string _numeroConta, double _saldo) : numeroConta(_numeroConta), saldo(_saldo) {}

    void exibirInfo()
    {
        cout << "Número da Conta: " << numeroConta << ", Saldo: R$ " << saldo << endl;
    }

    void sacar(double valor)
    {
        double taxaManutencao = 0.0;
        if (valor < 100.0)
        {
            taxaManutencao = 0.0;
        }
        else
        {
            taxaManutencao = valor * 0.05;
        }
        
        double totalSaque = valor + taxaManutencao;

        if (totalSaque <= saldo)
        {
            saldo -= totalSaque;
            cout << "Saque de R$ " << valor << " realizado com sucesso." << endl;
            if (taxaManutencao > 0.0)
                cout << "Taxa de manutenção de R$ " << taxaManutencao << " aplicada." << endl;
        }
        else
        {
            cout << "Saldo insuficiente para saque de R$ " << valor 
            << " + taxa de manutenção de R$ " << taxaManutencao << endl;
        }
    }

    ~contaBancaria() { cout << "Destrutor de contaBancaria" << endl; }
};

int main()
{
    contaBancaria conta1("123456789", 500.00);
    conta1.exibirInfo();

    conta1.sacar(50.00); 
    conta1.exibirInfo();

    conta1.sacar(200.00); 
    conta1.exibirInfo();

    conta1.sacar(300.00); 
    conta1.exibirInfo();

    return 0;
}