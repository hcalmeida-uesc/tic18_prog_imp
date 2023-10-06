#ifndef BANCO_DADOS_H
#define BANCO_DADOS_H

#include <iostream>
#include <vector>
#include <fstream>
#include "cliente.h"
#include "funcionario.h"
#include "veiculo.h"

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

            for(int i=0; i<dados.size()-1;i+=5){
                Cliente cli(
                    dados.at(i),
                    dados.at(i+1),
                    dados.at(i+2),
                    dados.at(i+3),
                    dados.at(i+4)
                );
                
                clientes.push_back(cli);
            }

            return clientes;
        }

        static void funcionariosParaArquivo(string arquivoNome,vector<Funcionario> funcionarios){
            vector<string> dados;

            for(Funcionario func : funcionarios){
                dados.push_back(func.cpf);
                dados.push_back(func.nome);
                dados.push_back(func.endereco);
                dados.push_back(func.telefone);
                dados.push_back(func.matricula);
            }

            salvarDados(arquivoNome,dados);
        }

        static vector<Funcionario> arquivoParaFuncionarios(string arquivoNome){
            vector<string> dados = recuperarDados(arquivoNome);

            vector<Funcionario> funcionarios;

            for(int i=0; i<dados.size()-1;i+=5){
                Funcionario func(
                            dados.at(i),
                            dados.at(i+1),
                            dados.at(i+2),
                            dados.at(i+3),
                            dados.at(i+4)
                        );
                funcionarios.push_back(func);
            }

            return funcionarios;
        }

        static void veiculosParaArquivo(string arquivoNome,vector<Veiculo> veiculos){
            vector<string> dados;

            for(Veiculo veiculo : veiculos){
                dados.push_back(veiculo.identificador);
                dados.push_back(veiculo.marca);
                dados.push_back(veiculo.modelo);
                dados.push_back(to_string(veiculo.anoFabricacao));
                dados.push_back(to_string(veiculo.precoPorDia));
            }

            salvarDados(arquivoNome,dados);
        }

        static vector<Veiculo> arquivoParaVeiculos(string arquivoNome){
            vector<string> dados = recuperarDados(arquivoNome);

            vector<Veiculo> veiculos;

            for(int i=0; i<dados.size()-1;i+=5){
                Veiculo veiculo(
                            dados.at(i),
                            dados.at(i+1),
                            dados.at(i+2),
                            stoi(dados.at(i+3)),
                            stof(dados.at(i+4))
                        );
                veiculos.push_back(veiculo);
            }

            return veiculos;
        }
};

#endif