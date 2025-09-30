#include <iostream>

using namespace std;

class MetodoPagamento
{
public:
    double valor;

    MetodoPagamento(double _valor) : valor(_valor) {}
    virtual void processarPagamento()
    {
        cout << "Processando pagamento de R$ " << valor << " com método genérico" << endl;
    };
    virtual ~MetodoPagamento() { cout << "Destruir MetodoPagamento" << endl; }
};

class CartaoCredito : public MetodoPagamento
{
public:
    string numeroCartao;
    string bandeira;

    CartaoCredito(double _valor, string _numeroCartao, string _bandeira) : MetodoPagamento(_valor), numeroCartao(_numeroCartao), bandeira(_bandeira) {}
    void processarPagamento() override
    {
        string ultimos4 = numeroCartao.substr(numeroCartao.length() - 4);
        cout << "Processando pagamento de R$ " << valor << " com Cartão de Crédito " << bandeira
             << ", 4 ultimos números do cartão: " << ultimos4 << endl;
    }
    ~CartaoCredito() override { cout << "Destruir CartaoCredito" << endl; }
};

class PayPal : public MetodoPagamento
{
public:
    string emailConta;
    PayPal(double _valor, string _emailConta) : MetodoPagamento(_valor), emailConta(_emailConta) {}
    void processarPagamento() override
    {
        cout << "Processando pagamento de R$ " << valor << " via PayPal, conta: " << emailConta << endl;
    }
    ~PayPal() override { cout << "Destruir PayPal" << endl; }
};

int main()
{
    MetodoPagamento *pagamentos[3];
    pagamentos[0] = new CartaoCredito(150.75, "1234567890123456", "Visa");
    pagamentos[1] = new PayPal(200.00, "tiago@live.com");
    pagamentos[2] = new MetodoPagamento(50.00);

    for (int i = 0; i < 3; ++i)
    {
        pagamentos[i]->processarPagamento();
    }

    for (int i = 0; i < 3; ++i)
    {
        delete pagamentos[i];
    }

    return 0;
}
