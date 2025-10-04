#include <iostream>
#include <string>
#include <stdexcept> // Para std::runtime_error, std::logic_error

// Função que pode lançar diferentes tipos de exceção
void processarDados(int valor) {
    if (valor < 0) {
        throw std::out_of_range("Valor negativo detectado!"); // Herda de std::logic_error
    }
    if (valor == 0) {
        throw std::runtime_error("Valor zero não processável!");
    }
    if (valor > 100) {
        throw "Valor muito grande!"; // Cuidado: lança const char*
    }
    std::cout << "Dados processados com sucesso: " << valor << std::endl;
}

int main() {
    std::cout << "--- Exemplo com Hierarquia de Exceções ---\n" << std::endl;

    // Teste 1: Valor negativo
    try {
        processarDados(-5);
    }
    catch (const std::out_of_range& e) { // Captura mais específica primeiro
        std::cerr << "Exceção Out of Range: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exceção Runtime Error: " << e.what() << std::endl;
    }
    catch (const std::logic_error& e) { // Captura um grupo de exceções (out_of_range herda de logic_error)
        std::cerr << "Exceção Logic Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) { // Captura qualquer std::exception restante
        std::cerr << "Exceção padrão: " << e.what() << std::endl;
    }
    catch (const char* msg) { // Captura char* (se precisar lidar com exceções 'legacy')
        std::cerr << "Exceção char*: " << msg << std::endl;
    }
    catch (...) { // Catch-all
        std::cerr << "Exceção desconhecida capturada neste bloco." << std::endl;
    }

    std::cout << "\n---" << std::endl;

    // Teste 2: Valor zero
    try {
        processarDados(0);
    }
    catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Exceção desconhecida." << std::endl;
    }

    std::cout << "\n---" << std::endl;

    // Teste 3: Valor muito grande (char*)
    try {
        processarDados(200);
    }
    catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
    catch (...) { // Captura o const char*
        std::cerr << "Exceção desconhecida (provavelmente const char*)." << std::endl;
    }

    std::cout << "\nPrograma continua a execução." << std::endl;
    return 0;
}