#include <iostream>
#include <string>

// Classe Base
class Publicacao {
public:
    std::string titulo;
    std::string autor;
    int numeroDePaginas;

    Publicacao(std::string _titulo, std::string _autor, int _paginas) :
        titulo(_titulo), autor(_autor), numeroDePaginas(_paginas) {}

    void exibirDetalhes() {
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Páginas: " << numeroDePaginas << std::endl;
    }
};

// Classe Derivada: Livro herda publicamente de Publicacao
class Livro : public Publicacao {
public:
    std::string isbn;

    Livro(std::string _titulo, std::string _autor, int _paginas, std::string _isbn) :
        Publicacao(_titulo, _autor, _paginas), // Chama o construtor da classe base
        isbn(_isbn) {}

    // Sobrescreve (ou estende) o método exibirDetalhes
    void exibirDetalhes() {
        Publicacao::exibirDetalhes(); // Chama o método da classe base
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

class Revista : public Publicacao {
public:
    std::string edicao;

    Revista(std::string _titulo, std::string _autor, int _paginas, std::string _edicao) :
        Publicacao(_titulo, _autor, _paginas), // Chama o construtor da classe base
        edicao(_edicao) {}

    // Sobrescreve (ou estende) o método exibirDetalhes
    void exibirDetalhes() {
        Publicacao::exibirDetalhes(); // Chama o método da classe base
        std::cout << "Edição: " << edicao << std::endl;
    }
};

class Artigo : public Publicacao {
public:
    std::string areaPesquisa;

    Artigo(std::string _titulo, std::string _autor, int _paginas, std::string _areaPesquisa) :
        Publicacao(_titulo, _autor, _paginas), // Chama o construtor da classe base
        areaPesquisa(_areaPesquisa) {}

    // Sobrescreve (ou estende) o método exibirDetalhes
    void exibirDetalhes() {
        Publicacao::exibirDetalhes(); // Chama o método da classe base
        std::cout << "Área de Pesquisa: " << areaPesquisa << std::endl;
    }
};

int main() {
    Livro meuLivro("O Senhor dos Anéis", "J.R.R. Tolkien", 1200, "978-0618053267");
    meuLivro.exibirDetalhes();

    std::cout << "\n";
    Revista minhaRevista("Elle", "Alguém aí", 20, "2025_09");
    minhaRevista.exibirDetalhes();

    std::cout << "\n";
    Artigo meuArtigo("Inteligência Artificial Generativa", "Alessandra e Henry", 27, "Computação");
    meuArtigo.exibirDetalhes();


    // Um objeto Livro É UMA Publicacao, então posso fazer:
    // Publicacao* p = &meuLivro; // Polimorfismo - será abordado mais tarde
    // p->exibirDetalhes(); // Com virtual function, chamaria o de Livro

    return 0;
}