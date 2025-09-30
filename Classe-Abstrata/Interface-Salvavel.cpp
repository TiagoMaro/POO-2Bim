#include <iostream>
#include <string>
#include <vector>

// Interface: ISalvavel (Classe Abstrata com apenas funções virtuais puras)
class ISalvavel {
public:
    // Todas as classes que implementarem ISalvavel devem saber como salvar e carregar
    virtual void salvar() = 0;
    virtual void carregar() = 0;

    // Destrutor virtual é uma boa prática para interfaces também
    virtual ~ISalvavel() {}
};

// Classe que implementa a interface ISalvavel
class ConfigManager : public ISalvavel {
private:
    std::string configData;
public:
    ConfigManager(std::string data) : configData(data) {}

    void salvar() override {
        std::cout << "Configurações salvas: " << configData << std::endl;
    }

    void carregar() override {
        std::cout << "Configurações carregadas: " << configData << std::endl;
    }
};

// Outra classe que implementa a interface ISalvavel
class GameManager : public ISalvavel {
private:
    int nivelAtual;
public:
    GameManager(int nivel) : nivelAtual(nivel) {}

    void salvar() override {
        std::cout << "Progresso do jogo salvo (Nível: " << nivelAtual << ")" << std::endl;
    }

    void carregar() override {
        std::cout << "Progresso do jogo carregado (Nível: " << nivelAtual << ")" << std::endl;
    }
};

int main() {
    std::cout << "--- Exemplo de Interface (ISalvavel) ---" << std::endl;

    std::vector<ISalvavel*> itensSalvaveis;
    itensSalvaveis.push_back(new ConfigManager("conexao_db_01"));
    itensSalvaveis.push_back(new GameManager(10));

    std::cout << "\nSalvando itens...\n";
    for (ISalvavel* item : itensSalvaveis) {
        item->salvar();
    }

    std::cout << "\nCarregando itens...\n";
    for (ISalvavel* item : itensSalvaveis) {
        item->carregar();
    }

    for (ISalvavel* item : itensSalvaveis) {
        delete item;
    }

    return 0;
}