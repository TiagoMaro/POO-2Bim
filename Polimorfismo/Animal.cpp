#include <iostream>
#include <string>

class Animal
{
public:
    std::string nome;
    Animal(std::string _nome) : nome(_nome) {}
    // DECLARANDO O MÉTODO COMO VIRTUAL NA SUPERCLASSE
    virtual void fazerBarulho()
    {
        std::cout << nome << " faz um barulho genérico." << std::endl;
    }
    virtual ~Animal() { std::cout << "Destrutor de Animal" << std::endl; } // Destrutor virtual
};

class Cachorro : public Animal
{
public:
    Cachorro(std::string _nome) : Animal(_nome) {}
    // Usando 'override' para indicar que está sobrescrevendo um método virtual
    void fazerBarulho() override
    {
        std::cout << nome << " late: Au Au!" << std::endl;
    }
    ~Cachorro() { std::cout << "Destrutor de Cachorro" << std::endl; }
};

class Gato : public Animal
{
public:
    Gato(std::string _nome) : Animal(_nome) {}
    void fazerBarulho() override
    {
        std::cout << nome << " mia: Miau!" << std::endl;
    }
    ~Gato() { std::cout << "Destrutor de Gato" << std::endl; }
};

int main()
{
    Animal *animais[3]; // Array de ponteiros para a Superclasse
    animais[0] = new Cachorro("Buddy");
    animais[1] = new Gato("Whiskers");
    animais[2] = new Animal("Bicho generico"); // Pode ter um objeto da Superclasse também

    for (int i = 0; i < 3; ++i)
    {
        animais[i]->fazerBarulho(); // Chama o método correto polimorficamente
    }

    // Importante: deletar os objetos alocados dinamicamente
    for (int i = 0; i < 3; ++i)
    {
        delete animais[i]; // Sem destrutor virtual em Animal, apenas o destrutor de Animal seria chamado
                           // Com destrutor virtual, o destrutor de Cachorro/Gato será chamado primeiro.
    }

    return 0;
}