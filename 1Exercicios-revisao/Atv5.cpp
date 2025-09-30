#include <iostream>
#include <string>

using namespace std;

class Dispositivo
{
    protected:
        string modelo;
    
    public:
        Dispositivo(string _modelo) : modelo(_modelo) {}
        virtual ~Dispositivo() { cout << "Destrutor de Dispositivo" << endl; }
};

class Smartphone : public Dispositivo
{    
    protected:
        string sistemaOperacional;
    
    public:
        Smartphone(string _modelo, string _sistemaOperacional) : Dispositivo(_modelo), sistemaOperacional(_sistemaOperacional) {}
        ~Smartphone() { cout << "Destrutor de Smartphone" << endl; }
};

int main()
{
    Dispositivo* d2 = new Smartphone("iPhone 13", "iOS");

    delete d2;

    return 0;
}