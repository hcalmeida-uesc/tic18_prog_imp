#include <iostream>
#include <vector>

using namespace std;

class Pessoa{
    public:
        string nome;

        friend ostream& operator<<(ostream& o, Pessoa const& p){
            o << p.nome;
            return o;
        }
};


template <typename T> class ListaGenerica{
    vector<T> *elementos;
    public:

        ListaGenerica(){
            this->elementos = new vector<T>();
        }

        void adicionar(T elemento){
            this->elementos->push_back(elemento);
        }

        T remover(){
            T temp;
            temp = this->elementos->back();
            this->elementos->pop_back();
            return temp;
        }

        void listar(){
            for(auto el : *this->elementos){
                cout << el << endl;
            }
        }
};

int main(){

    cout << "Lista de inteiros" << endl;
    ListaGenerica<int> *lista = new ListaGenerica<int>();
    lista->adicionar(10);
    lista->adicionar(12);
    lista->adicionar(14);
    lista->adicionar(20);
    lista->listar();
    lista->remover();
    lista->listar();

    cout << endl << "Lista de strings" << endl;
    ListaGenerica<string> *listaString = new ListaGenerica<string>();
    listaString->adicionar("Banana");
    listaString->adicionar("Whey");
    listaString->adicionar("Cacau");
    listaString->listar();
    listaString->remover();
    listaString->listar();

    cout << endl << "Lista de Pessoas" << endl;
    ListaGenerica<Pessoa> *listaPessoa = new ListaGenerica<Pessoa>();
    Pessoa p;
    p.nome = "Nicole";
    listaPessoa->adicionar(p);
    p.nome = "Hélder";
    listaPessoa->adicionar(p);
    p.nome = "Gilvana";
    listaPessoa->adicionar(p);
    listaPessoa->listar();
    listaPessoa->remover();
    listaPessoa->listar();

    return 0;
}