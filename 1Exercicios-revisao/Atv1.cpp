#include <iostream>
#include <string>

using namespace std;

class Produto
{
    protected:
        string nome;
        double preco;
    
    public:
        Produto(string _nome, double _preco) : nome(_nome), preco(_preco) {}
        virtual void exibirInfo()
        {
            cout << "Produto: " << nome << ", Preço: R$ " << preco << endl;
        }
        virtual ~Produto() { cout << "Destrutor de Produto" << endl; }
};

class Livro : public Produto
{
    private:
        string autor;
        int numPaginas;
    
    public:
        Livro(string _nome, double _preco, string _autor, int _numPaginas) : 
        Produto(_nome, _preco), autor(_autor), numPaginas(_numPaginas) {}
        void exibirInfo() override
        {
            cout << "Livro: " << nome 
            << "\nPáginas: " << numPaginas 
            <<"\nAutor: " << autor 
            << "\nPreço: R$ " << preco << endl;
        }
        ~Livro() { cout << "Destrutor de Livro" << endl; }
};

int main()
{
    Livro livro1("1984", 39.90, "George Orwell", 328);

    livro1.exibirInfo();

    return 0;
}