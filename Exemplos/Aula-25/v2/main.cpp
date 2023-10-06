#include <iostream>
#include <ctime>
#include <cstring>
#include <vector>
#include "headers/usuario.h"
#include "headers/cliente.h"
#include "headers/funcionario.h"
#include "headers/veiculo.h"
#include "headers/aluguel.h"
#include "headers/utilidades.h"
#include "headers/bancoDeDados.h"

using namespace std;

int main(){
    time_t rawtime;
    struct tm *timeinfo, time2;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    memcpy(&time2, timeinfo, sizeof(time2));

    time2.tm_mday = 8;


    
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
/*
    vector<string> strBuff;
    string buff;

    getline(cin >> ws, buff);
    strBuff.push_back(buff);
    getline(cin >> ws, buff);
    strBuff.push_back(buff);time2
    getline(cin >> ws, buff);
    strBuff.push_back(buff);
    getline(cin >> ws, buff);
    strBuff.push_back(buff);

    bancoClientes.push_back(func1.cadastrarCliente( strBuff.at(0),
                                                    strBuff.at(1),
                                                    strBuff.at(2),
                                                    strBuff.at(3),
                                                    strBuff.at(4)));
*/
    BancoDeDados::clientesParaArquivo("clientes.txt",bancoClientes);

    vector<Veiculo> bancoVeiculos;

    bancoVeiculos.push_back(func1.cadastrarVeiculo("OUP-4062","HONDA","CIVIC LXR",2014,100));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("JMV-6030","FORD","CORSA HATCH",2000,40));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("NPM-1030","FERRARI","F40 SPYDER",2015,10000));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("OUP-6030","VOLKSWAGEM","FUSCA 1.6",1960,25));

    BancoDeDados::veiculosParaArquivo("veiculos.txt",bancoVeiculos);

    bancoVeiculos = BancoDeDados::arquivoParaVeiculos("veiculos.txt");

    Cliente clienteTeste = bancoClientes.at(0);
    Funcionario funcionarioTeste = bancoFuncionarios.at(0);
    Veiculo veiculoTeste = bancoVeiculos.at(0);
    Aluguel novoAluguel = funcionarioTeste.AlugarVeiculo(&clienteTeste,&funcionarioTeste,&veiculoTeste,timeinfo,&time2);

    cout << novoAluguel.identificador << endl;
    cout << "Data de Inicio:";
    Utilidades::imprimirData(novoAluguel.dataInicio);
    cout << "Data de Termino:";
    Utilidades::imprimirData(novoAluguel.dataTermino);
    cout << "Data de Devolucao:";
    Utilidades::imprimirData(novoAluguel.dataDevolucao);
    cout << "Valor Final:";
    cout << novoAluguel.CalcularValorFinal() << endl;

    struct tm devolucaoTeste;

    memcpy(&devolucaoTeste, &time2, sizeof(struct tm));

    devolucaoTeste.tm_mday += 5;

    novoAluguel.dataDevolucao = &devolucaoTeste;

    cout << "Data de Devolucao:";
    Utilidades::imprimirData(novoAluguel.dataDevolucao);
    cout << "Quantidade de dias:";
    cout << Utilidades::diferencaEmDiasEntreDatas(novoAluguel.dataInicio,novoAluguel.dataDevolucao) << endl;
    cout << "Preço do veiculo por dia:";
    cout << novoAluguel.veiculo->precoPorDia << endl;
    cout << "Valor Final:";
    cout << novoAluguel.CalcularValorFinal() << endl;

    return 0;
}