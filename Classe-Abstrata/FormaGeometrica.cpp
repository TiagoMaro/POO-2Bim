#include <iostream>
#include <string>
#include <vector>
#include <cmath> // Para M_PI

// Define M_PI se não estiver definido
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Classe Abstrata: FormaGeometrica
class FormaGeometrica {
protected:
    std::string cor;
public:
    FormaGeometrica(std::string _cor) : cor(_cor) {}

    // Função virtual pura: Obriga as subclasses a implementarem calcularArea()
    virtual double calcularArea() = 0;

    // Função virtual pura: Obriga as subclasses a implementarem desenhar()
    virtual void desenhar() = 0;

    // Método não-virtual que pode ser usado pelas subclasses
    void exibirCor() {
        std::cout << "Cor: " << cor << std::endl;
    }

    // Destrutor virtual: Essencial para herança polimórfica
    virtual ~FormaGeometrica() {
        std::cout << "Destrutor de FormaGeometrica (" << cor << ") chamado." << std::endl;
    }
};

// Subclasse Concreta: Retangulo
class Retangulo : public FormaGeometrica {
private:
    double largura;
    double altura;
public:
    Retangulo(std::string _cor, double _largura, double _altura) :
        FormaGeometrica(_cor), largura(_largura), altura(_altura) {}

    // Implementação OBRIGATÓRIA de calcularArea()
    double calcularArea() override {
        return largura * altura;
    }

    // Implementação OBRIGATÓRIA de desenhar()
    void desenhar() override {
        std::cout << "Desenhando Retângulo (Cor: " << cor
                  << ", Largura: " << largura << ", Altura: " << altura << ")" << std::endl;
    }

    ~Retangulo() override {
        std::cout << "Destrutor de Retangulo (" << cor << ") chamado." << std::endl;
    }
};

// Subclasse Concreta: Circulo
class Circulo : public FormaGeometrica {
private:
    double raio;
public:
    Circulo(std::string _cor, double _raio) :
        FormaGeometrica(_cor), raio(_raio) {}

    // Implementação OBRIGATÓRIA de calcularArea()
    double calcularArea() override {
        return M_PI * raio * raio;
    }

    // Implementação OBRIGATÓRIA de desenhar()
    void desenhar() override {
        std::cout << "Desenhando Círculo (Cor: " << cor
                  << ", Raio: " << raio << ")" << std::endl;
    }

    ~Circulo() override {
        std::cout << "Destrutor de Circulo (" << cor << ") chamado." << std::endl;
    }
};

int main() {
    // FormaGeometrica f("Vermelho"); // ERRO: Não é possível instanciar uma classe abstrata

    Retangulo r("Azul", 10.0, 5.0);
    Circulo c("Verde", 7.0);

    r.desenhar();
    r.exibirCor();
    std::cout << "Área do Retângulo: " << r.calcularArea() << std::endl;

    std::cout << "\n";

    c.desenhar();
    c.exibirCor();
    std::cout << "Área do Círculo: " << c.calcularArea() << std::endl;

    // Demonstração de polimorfismo com classes abstratas
    std::cout << "\n--- Polimorfismo com ponteiros de classe abstrata ---\n";
    std::vector<FormaGeometrica*> formas;
    formas.push_back(new Retangulo("Vermelho", 8, 3));
    formas.push_back(new Circulo("Amarelo", 4));

    for (FormaGeometrica* f : formas) {
        f->desenhar();
        std::cout << "Área: " << f->calcularArea() << std::endl;
    }

    for (FormaGeometrica* f : formas) {
        delete f;
    }

    return 0;
}