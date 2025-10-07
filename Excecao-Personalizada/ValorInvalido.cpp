#include <iostream>
#include <string>
#include <stdexcept> // Para std::logic_error

class ValorInvalidoExcecao : public std::logic_error {
public:
    ValorInvalidoExcecao(const std::string& mensagem, int valorRecebido, int limiteMin, int limiteMax)
        : std::logic_error(mensagem + " (Valor: " + std::to_string(valorRecebido) +
                           ", Esperado entre " + std::to_string(limiteMin) +
                           " e " + std::to_string(limiteMax) + ")"),
          valorRecebido_(valorRecebido), limiteMin_(limiteMin), limiteMax_(limiteMax) {}

    // Getters para acessar as informações adicionais
    int getValorRecebido() const noexcept { return valorRecebido_; }
    int getLimiteMin() const noexcept { return limiteMin_; }
    int getLimiteMax() const noexcept { return limiteMax_; }

private:
    int valorRecebido_;
    int limiteMin_;
    int limiteMax_;
};

void processarNumero(int numero) {
    const int MIN = 10;
    const int MAX = 50;
    if (numero < MIN || numero > MAX) {
        throw ValorInvalidoExcecao("Número fora dos limites permitidos", numero, MIN, MAX);
    }
    std::cout << "Número " << numero << " processado com sucesso." << std::endl;
}

int main_multi_attr() {
    std::cout << "--- Exemplo 2: ValorInvalidoExcecao com Atributos ---\n" << std::endl;

    try {
        processarNumero(5); // Valor muito baixo
    }
    catch (const ValorInvalidoExcecao& e) {
        std::cerr << "Exceção Valor Inválido: " << e.what() << std::endl;
        std::cerr << "  Detalhes: Recebido: " << e.getValorRecebido()
                  << ", Mín: " << e.getLimiteMin()
                  << ", Máx: " << e.getLimiteMax() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exceção padrão: " << e.what() << std::endl;
    }

    std::cout << "\n---\n\n";

    try {
        processarNumero(30); // Valor válido
    }
    catch (const ValorInvalidoExcecao& e) {
        std::cerr << "Exceção Valor Inválido: " << e.what() << std::endl;
    }
    std::cout << "\nPrograma continua a execução." << std::endl;
    return 0;
}

int main(){
    main_multi_attr();
    return 0;
}