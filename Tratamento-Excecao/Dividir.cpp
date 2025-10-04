#include <iostream>
#include <string>
#include <stdexcept> // Para std::runtime_error

double dividir(double numerador, double denominador) {
    if (denominador == 0) {
        // Lançando uma exceção do tipo std::runtime_error
        throw std::runtime_error("Erro: Divisão por zero não permitida!");
    }
    return numerador / denominador;
}

int main() {
    std::cout << "--- Exemplo Básico de Tratamento de Exceções ---\n" << std::endl;

    try {
        double resultado = dividir(10.0, 2.0);
        std::cout << "Resultado da divisão (10/2): " << resultado << std::endl;


        resultado = dividir(5.0, 0.0); // Esta linha lançará uma exceção
        std::cout << "Esta linha não será executada." << std::endl; // Nunca alcançada
    }
    catch (const std::runtime_error& e) { // Captura exceções do tipo std::runtime_error
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
    catch (const std::string& msg) { // Exemplo de captura de string (evitar, usar std::exception)
        std::cerr << "Exceção de string capturada: " << msg << std::endl;
    }
    catch (...) { // Catch-all: captura qualquer outra exceção
        std::cerr << "Exceção desconhecida capturada." << std::endl;
    }

    std::cout << "\nPrograma continua a execução após o tratamento da exceção." << std::endl;
    return 0;
}