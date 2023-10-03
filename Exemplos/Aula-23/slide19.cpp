#include <iostream>

using namespace std;

class ItemBiblioteca{
    public:
        string titulo, autor;
        int copiasDisponiveis;

        ItemBiblioteca(string _titulo,
                       string _autor,
                       int _copias){
            
            titulo = _titulo;
            autor = _autor;
            copiasDisponiveis = _copias;
        }
};

class Livro : public ItemBiblioteca{
    public:
        int nroPaginas;
        Livro(  string _titulo,
                string _autor,
                int _copias,
                int _nroPaginas):
                    ItemBiblioteca( _titulo,
                                    _autor,
                                    _copias){

            nroPaginas = _nroPaginas;
        }
};

class Dvd : public ItemBiblioteca{
    public:
        int duracaoSegundos;

        Dvd(  string _titulo,
                string _autor,
                int _copias,
                int _duracao):
                    ItemBiblioteca( _titulo,
                                    _autor,
                                    _copias){

            duracaoSegundos = _duracao;
        }
};

int main(){

    Livro livro1("O Principe","Maquiavel",5,1837);
    Dvd dvd1("Calcinha Preta","Calcinha Preta",1,216000);

    cout << livro1.titulo << endl;
    cout << dvd1.titulo << endl;

    return 0;
}