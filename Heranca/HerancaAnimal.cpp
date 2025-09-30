#include <iostream>
#include <string>

class Animal {
protected: // Acessível por Animal e classes derivadas
    std::string nome;
    int idade;

public:
    Animal(std::string _nome, int _idade) : nome(_nome), idade(_idade) {}
    void fazerBarulho() {
        std::cout << "Animal faz barulho." << std::endl;
    }
};

class Cachorro : public Animal {
public:
    Cachorro(std::string _nome, int _idade) : Animal(_nome, _idade) {}

    void latir() {
        std::cout << nome << " (idade: " << idade << ") está latindo: Au Au!" << std::endl;
    }
    // Tentativa de acesso a 'nome' e 'idade' diretamente (válido porque são protected)
    void exibirInfo() {
        std::cout << "Nome do cachorro: " << nome << ", Idade: " << idade << std::endl;
    }
};

int main() {
    Cachorro meuCachorro("Rex", 3);
    meuCachorro.latir();
    meuCachorro.fazerBarulho(); // Método herdado
    meuCachorro.exibirInfo();
    // std::cout << meuCachorro.nome; // ERRO: 'nome' é protected
    return 0;
}