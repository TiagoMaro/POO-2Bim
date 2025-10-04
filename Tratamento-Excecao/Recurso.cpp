#include <iostream>
#include <memory> // Para std::unique_ptr
#include <stdexcept>

class Recurso {
public:
    Recurso(const std::string& nome) : nome_(nome) {
        std::cout << "Recurso "" << nome_ << "" adquirido." << std::endl;
    }
    ~Recurso() {
        std::cout << "Recurso "" << nome_ << "" liberado." << std::endl;
    }
    void operar() {
        std::cout << "Operando Recurso "" << nome_ << ""..." << std::endl;
        // Simula uma falha
        if (nome_ == "Falho") {
            throw std::runtime_error("Falha ao operar o Recurso Falho!");
        }
    }
private:
    std::string nome_;
};

void funcaoQueFalha() {
    // Recurso adquirido no stack
    Recurso r1("Local1");

    // Recurso adquirido via unique_ptr (RAII)
    std::unique_ptr<Recurso> r2 = std::make_unique<Recurso>("Falho");

    r1.operar();
    r2->operar(); // Lançará uma exceção aqui

    std::cout << "Esta linha não será executada." << std::endl;
}

int main() {
    std::cout << "--- Exemplo de RAII com Exceções ---\n" << std::endl;

    try {
        funcaoQueFalha();
    }
    catch (const std::exception& e) {
        std::cerr << "Exceção capturada em main: " << e.what() << std::endl;
    }

    std::cout << "\nPrograma continua a execução (recursos liberados)." << std::endl;
    return 0;
}