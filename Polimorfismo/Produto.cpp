#include <iostream>
#include <string>
#include <iomanip> // Para formatar a saída do double

class Produto {
public:
    std::string nome;
    double preco;

    // Construtor 1
    Produto(std::string _nome, double _preco) : nome(_nome), preco(_preco) {}

    // Construtor 2 (sobrecarregado)
    Produto(std::string _nome) : nome(_nome), preco(0.0) {}

    // Construtor 3 (sobrecarregado)
    Produto() : nome("Sem Nome"), preco(0.0) {}

    void exibirInfo() {
        std::cout << "Produto: " << nome << ", Preço: R$" << std::fixed << std::setprecision(2) << preco << std::endl;
    }

    // Sobrecarga 1 de aplicarDesconto
    void aplicarDesconto(double percentual) {
        preco -= preco * (percentual / 100.0);
        std::cout << "Desconto de " << percentual << "% aplicado." << std::endl;
    }

    // Sobrecarga 2 de aplicarDesconto
    void aplicarDesconto(double percentual, bool ehMembro) {
        double descontoTotal = percentual;
        if (ehMembro) {
            descontoTotal += 5.0; // 5% adicional para membros
        }
        preco -= preco * (descontoTotal / 100.0);
        std::cout << "Desconto de " << descontoTotal << "% (incluindo membro) aplicado." << std::endl;
    }
};

int main() {
    Produto p1("Teclado Gamer", 250.00);
    p1.exibirInfo();
    p1.aplicarDesconto(10);
    p1.exibirInfo();

    Produto p2("Mouse Sem Fio");
    p2.exibirInfo(); // Preço será 0.0 inicialmente
    p2.preco = 120.00; // Define o preço depois
    p2.exibirInfo();
    p2.aplicarDesconto(15, true); // Com desconto adicional para membro
    p2.exibirInfo();

    return 0;
}