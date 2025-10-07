#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

class FalhaAutenticacaoExcecao : public std::runtime_error
{
private:
    string usuarioTentativa;

public:
    FalhaAutenticacaoExcecao(const string &mensagem, string usuarioTentativa_)
        : runtime_error(mensagem + "Autenticação deve ser feita apenas por um administrador"
            "\n""Usuário que tentou autenticar: " + usuarioTentativa_),
          usuarioTentativa(usuarioTentativa_)
    {
    }

    string getUsuario() const noexcept { return usuarioTentativa; }
};

void autenticar(const string &usuario, const string &senha)
{
    const string userAdm = "administrador";
    const string senhaAdm = "12345";
    if (usuario != userAdm || senha != senhaAdm)
    {
        throw FalhaAutenticacaoExcecao("Usuário ou senha inválidos \n", usuario);
    }
    cout << "Autenticado com sucesso" << endl;
}

int main()
{
    try
    {
        autenticar("administrado", "12345");
    }
    catch (const FalhaAutenticacaoExcecao &e)
    {
        cerr << e.what() << endl;
        cerr << "Usuáŕio: " << e.getUsuario() << endl;
    }
}