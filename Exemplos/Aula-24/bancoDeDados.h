#include <iostream>
#include <vector>
#include <fstream>
#include "aluguel.h"

using namespace std;

class BancoDeDados{
    public:
        static void salvarDados(string arquivoNome, vector<string> dados){
            ofstream arquivo;
            
            vector<string>::iterator it;
            arquivo.open(arquivoNome,ios_base::out);
            
            if (arquivo.is_open()) {
                for(it = dados.begin(); it != dados.end(); it++){
                    arquivo << *it << endl;
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }

        static vector<string> recuperarDados(string arquivoNome){
            ifstream arquivo;
            vector<string> dados;
            arquivo.open(arquivoNome,ios_base::in);
            
            if (arquivo.is_open()) {
                string linha;
            while (arquivo.eof() == false) {
                    getline(arquivo, linha);
                    dados.push_back(linha);
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }

            return dados;
        }

        static void clientesParaArquivo(string arquivoNome,vector<Cliente> clientes){
            vector<string> dados;

            for(Cliente cli : clientes){
                dados.push_back(cli.cpf);
                dados.push_back(cli.nome);
                dados.push_back(cli.endereco);
                dados.push_back(cli.telefone);
                dados.push_back(cli.habilitacao);
            }

            salvarDados(arquivoNome,dados);
        }

        static vector<Cliente> arquivoParaClientes(string arquivoNome){
            vector<string> dados = recuperarDados(arquivoNome);

            vector<Cliente> clientes;

            cout << dados.size() << endl;

            for(int i=0; i<dados.size()-1;i+=5){
                Cliente cli;
                cli.cpf = dados.at(i);
                cli.nome = dados.at(i+1);
                cli.endereco = dados.at(i+2);
                cli.telefone = dados.at(i+3);
                cli.habilitacao = dados.at(i+4);
                clientes.push_back(cli);
            }

            return clientes;
        }
};