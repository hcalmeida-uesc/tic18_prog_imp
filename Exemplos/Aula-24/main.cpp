#include <iostream>
#include "bancoDeDados.h"

using namespace std;

int main(){
    Funcionario func1("12234455","Ulian","Ilheus","454564","123456");
/*
    Cliente cli = func1.cadastrarCliente("22222222","Hélder", "Itabuna","646746464","334343");

    vector<Cliente> clientes;

    clientes.push_back(cli);
    cli = func1.cadastrarCliente("11111111","Alan","Ilheus","34343","6666666");
    clientes.push_back(cli);

    BancoDeDados::clientesParaArquivo("clientes.txt",clientes);
*/
    vector<Cliente> novaColecao;

    novaColecao = BancoDeDados::arquivoParaClientes("clientes.txt");

    cout << novaColecao.size() << endl;
    cout << novaColecao.at(0).nome << endl;
    cout << novaColecao.at(1).nome << endl;
    cout << novaColecao.at(2).nome << endl;
    cout << novaColecao.at(3).nome << endl;

    return 0;
}