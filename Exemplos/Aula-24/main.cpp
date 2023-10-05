#include <iostream>
#include "bancoDeDados.h"

using namespace std;

int main(){
    Funcionario func1("12234455","Ulian","Ilheus","454564","123456");

    vector<Funcionario> bancoFuncionarios;

    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000011","Teste1","Bahia","73333333","000001"));
    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000012","Teste2","Bahia","73333333","000002"));
    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000013","Teste3","Bahia","73333333","000003"));
    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000014","Teste4","Bahia","73333333","000004"));

    BancoDeDados::funcionariosParaArquivo("funcionarios.txt",bancoFuncionarios);

    vector<Cliente> bancoClientes;

    bancoClientes.push_back(func1.cadastrarCliente("00000000021","Hélder", "Itabuna","646746464","101010"));
    bancoClientes.push_back(func1.cadastrarCliente("00000000022","Ulian", "Salvador","646746464","111111"));
    bancoClientes.push_back(func1.cadastrarCliente("00000000023","Jéssica", "Ilhéus","646746464","121212"));
    bancoClientes.push_back(func1.cadastrarCliente("00000000024","Paulo", "Arábia","646746464","131313"));

    vector<string> strBuff;
    string buff;

    getline(cin >> ws, buff);
    strBuff.push_back(buff);
    getline(cin >> ws, buff);
    strBuff.push_back(buff);
    getline(cin >> ws, buff);
    strBuff.push_back(buff);
    getline(cin >> ws, buff);
    strBuff.push_back(buff);
    getline(cin >> ws, buff);
    strBuff.push_back(buff);

    bancoClientes.push_back(func1.cadastrarCliente( strBuff.at(0),
                                                    strBuff.at(1),
                                                    strBuff.at(2),
                                                    strBuff.at(3),
                                                    strBuff.at(4)));

    BancoDeDados::clientesParaArquivo("clientes.txt",bancoClientes);

    vector<Veiculo> bancoVeiculos;

    bancoVeiculos.push_back(func1.cadastrarVeiculo("OUP-4062","HONDA","CIVIC LXR",2014,100));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("JMV-6030","FORD","CORSA HATCH",2000,40));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("NPM-1030","FERRARI","F40 SPYDER",2015,10000));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("OUP-6030","VOLKSWAGEM","FUSCA 1.6",1960,25));

    BancoDeDados::veiculosParaArquivo("veiculos.txt",bancoVeiculos);

    bancoVeiculos = BancoDeDados::arquivoParaVeiculos("veiculos.txt");


    return 0;
}