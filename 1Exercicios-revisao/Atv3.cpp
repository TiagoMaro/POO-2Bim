#include <iostream>
#include <string>

using namespace std;

class Veiculo
{
    protected:
        int velocidade;
    
    public:
        Veiculo(int _velocidade) : velocidade(_velocidade) {}
        virtual void mover ()
        {
            cout << "Veículo se movendo a " << velocidade << " km/h" << endl;
        }
        virtual ~Veiculo() { cout << "Destrutor de Veículo" << endl; }
};

class Carro : public Veiculo
{    
    public:
        Carro(int _velocidade) : Veiculo(_velocidade) {}
        void mover() override
        {
            cout << "Carro acelerando a: " << velocidade << " km/h" << endl;
        }
        ~Carro() { cout << "Destrutor de Carro" << endl; }
};

int main()
{
    Veiculo* v1 = new Veiculo(60);
    Veiculo* v2 = new Carro(120);

    v1->mover();
    v2->mover();

    delete v1;
    delete v2;

    return 0;
}