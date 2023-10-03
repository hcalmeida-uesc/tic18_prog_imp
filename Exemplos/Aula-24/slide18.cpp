#include <iostream>
#include <vector>

using namespace std;

class Estado{
    public:
        string nome;
        string sigla;

};

class Cidade{
    public:
        string nome;
        Estado *estado;

};

int main(){
    vector<Estado*> colecaoEstados;
    vector<Cidade> colecaoCidades;

    Estado estadoTemp;
    Cidade cidadeTemp;

    estadoTemp.nome = "Bahia";
    estadoTemp.sigla = "BA";
    
    colecaoEstados.push_back(&estadoTemp);

    cidadeTemp.estado = &estadoTemp;
    cidadeTemp.nome = "Itabuna";

    cout << cidadeTemp.nome << " - ";
    cout << cidadeTemp.estado->nome << endl;
    cout << colecaoEstados[0]->nome << endl;

    estadoTemp.nome = "Baea";

    cout << cidadeTemp.nome << " - ";
    cout << cidadeTemp.estado->nome << endl;
    cout << colecaoEstados[0]->nome << endl;
    
    return 0;
}