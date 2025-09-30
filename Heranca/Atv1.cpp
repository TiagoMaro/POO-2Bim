#include <iostream>
#include <string>

// Classe Base
class Pessoa {
protected:
    std::string nome;
    int idade;
public:
    Pessoa(std::string _nome, int _idade) : nome(_nome), idade(_idade) {}
    void apresentar() {
        std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
    }
};

// Classe Derivada Aluno
class Aluno : public Pessoa {
private: // Exemplo de atributo privado
    std::string matricula;
    std::string curso;
public:
    Aluno(std::string _nome, int _idade, std::string _matricula, std::string _curso) :
        Pessoa(_nome, _idade), matricula(_matricula), curso(_curso) {}
    void apresentar() {
        Pessoa::apresentar(); // Chama o apresentar da Pessoa
        std::cout << "Matrícula: " << matricula << ", Curso: " << curso << std::endl;
    }
};

// Classe Derivada Professor
class Professor : public Pessoa {
private:
    std::string disciplina;
    double salario;
public:
    Professor(std::string _nome, int _idade, std::string _disciplina, double _salario) :
        Pessoa(_nome, _idade), disciplina(_disciplina), salario(_salario) {}
    void apresentar() {
        Pessoa::apresentar(); // Chama o apresentar da Pessoa
        std::cout << "Disciplina: " << disciplina << ", Salário: R$" << salario << std::endl;
    }
};

int main() {
    Aluno aluno1("Ana Silva", 20, "2023001", "Engenharia de Software");
    Professor prof1("Carlos Santos", 45, "Programação Orientada a Objetos", 3500.00);

    std::cout << "--- Informações do Aluno ---" << std::endl;
    aluno1.apresentar();

    std::cout << "\n--- Informações do Professor ---" << std::endl;
    prof1.apresentar();

    return 0;
}