#include <iostream>
#include <string>

using namespace std;

class Relatorio
{
    protected:
        string titulo;
    
    public:
        Relatorio(string _titulo) : titulo(_titulo) {}
        virtual string gerarConteudo() = 0; 
        void exibirRelatorio()
        {
            cout << "Relatório: " << titulo << endl;
            cout << gerarConteudo() << endl;
        }
        virtual ~Relatorio() { cout << "Destrutor de Relatório" << endl; }
};

class RelatorioVendas : public Relatorio
{
    private:
        double totalVendas;
    
    public:
        RelatorioVendas(string _titulo, double _totalVendas) : 
        Relatorio(_titulo), totalVendas(_totalVendas) {}
        string gerarConteudo() override
        {
            return "Total de Vendas R$ " + to_string(totalVendas);
        }
        ~RelatorioVendas() { cout << "Destrutor de Relatório de Vendas" << endl; }
};

int main()
{
    Relatorio* relatorio = new RelatorioVendas("Relatório de Vendas", 1500.75);
    relatorio->exibirRelatorio();

    delete relatorio;

    return 0;
}