#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IControlavel {
    public:
        virtual string ligar() = 0;
        virtual string desligar() = 0;
        virtual string status() = 0;
        virtual ~IControlavel() {
            cout << "Destrutor de IControlavel chamado." << endl;
        }
};

class Televisao : public IControlavel {
    private:
        bool ligada;
    public:
        Televisao() : ligada(false) {}

        string ligar() override {
            ligada = true;
            return "Televisão ligada.";
        }

        string desligar() override {
            ligada = false;
            return "Televisão desligada.";
        }

        string status() override {
            return ligada ? "Televisão está ligada." : "Televisão está desligada.";
        }

        ~Televisao() {
            cout << "Destrutor de Televisao chamado." << endl;
        }
};

class LampadaInteligente : public IControlavel {
    private:
        bool ligada;
    public:
        LampadaInteligente() : ligada(false) {}

        string ligar() override {
            ligada = true;
            return "Lâmpada inteligente ligada.";
        }

        string desligar() override {
            ligada = false;
            return "Lâmpada inteligente desligada.";
        }

        string status() override {
            return ligada ? "Lâmpada inteligente está ligada." : "Lâmpada inteligente está desligada.";
        }

        ~LampadaInteligente() {
            cout << "Destrutor de LampadaInteligente chamado." << endl;
        }
};

int main() {
    cout << "--- Exemplo de Classe Abstrata (IControlavel) ---" << endl;

    vector<IControlavel*> dispositivos;
    dispositivos.push_back(new Televisao());
    dispositivos.push_back(new LampadaInteligente());

    for (IControlavel* disp : dispositivos) {
        cout << disp->ligar() << endl;
        cout << disp->status() << endl;
        cout << disp->desligar() << endl;
        cout << disp->status() << endl;
        cout << endl;
    }

    for (IControlavel* disp : dispositivos) {
        delete disp;
    }

    return 0;
}