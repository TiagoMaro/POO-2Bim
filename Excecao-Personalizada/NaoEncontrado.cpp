#include <iostream>
#include <string>
#include <stdexcept> // Para std::runtime_error
#include <fstream>   // Para std::ifstream

// 1. Definindo a exceção personalizada
class ArquivoNaoEncontradoExcecao : public std::runtime_error {
public:
    // Construtor: Chama o construtor da classe base (std::runtime_error)
    // e passa uma mensagem de erro personalizada.
    ArquivoNaoEncontradoExcecao(const std::string& nomeArquivo)
        : std::runtime_error("Erro: Arquivo "" + nomeArquivo + "" não encontrado."),
          nomeArquivo_(nomeArquivo) {} // Inicializa o membro específico

    // O método what() já é sobrescrito por std::runtime_error,
    // que retorna a string passada no construtor.
    // Podemos adicionar um getter para o nome do arquivo se quisermos.
    const std::string& getNomeArquivo() const noexcept {
        return nomeArquivo_;
    }

private:
    std::string nomeArquivo_; // Membro adicional para guardar o nome do arquivo
};

// Função que utiliza a exceção personalizada
void abrirArquivo(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        // Lança a exceção personalizada
        throw ArquivoNaoEncontradoExcecao(caminhoArquivo);
    }
    std::cout << "Arquivo "" << caminhoArquivo << "" aberto com sucesso." << std::endl;
    arquivo.close();
}

int main() {
    std::cout << "--- Exemplo 1: ArquivoNaoEncontradoExcecao ---\n" << std::endl;

    // Tenta abrir um arquivo que existe
    try {
        abrirArquivo("main.cpp"); // Supondo que este arquivo exista
    }
    catch (const ArquivoNaoEncontradoExcecao& e) {
        std::cerr << "Exceção específica capturada: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exceção padrão capturada: " << e.what() << std::endl;
    }

    std::cout << "\n---\n";

    // Tenta abrir um arquivo que não existe
    try {
        abrirArquivo("arquivo_que_nao_existe.txt");
    }
    catch (const ArquivoNaoEncontradoExcecao& e) { // Captura a exceção específica
        std::cerr << "Exceção ESPECÍFICA capturada: " << e.what() << std::endl;
        std::cerr << "Nome do arquivo falho: " << e.getNomeArquivo() << std::endl;
    }
    catch (const std::exception& e) { // Catch-all para outras exceções std::
        std::cerr << "Exceção padrão capturada: " << e.what() << std::endl;
    }
    std::cout << "\nPrograma continua a execução." << std::endl;
    return 0;
}