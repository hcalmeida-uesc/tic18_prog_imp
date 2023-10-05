#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Usuario{
    public:
        string cpf;
        string nome;
        string endereco;
        string telefone;

        Usuario(string _cpf,
                string _nome,
                string _endereco,
                string _telefone){
            
            cpf = _cpf;
            nome = _nome;
            endereco = _endereco;
            telefone = _telefone;
        }
};

class Cliente : public Usuario{
    public:
        string habilitacao;

        //Cliente():Usuario("","","",""){}
        
        Cliente(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _habilitacao):Usuario(_cpf,
                                             _nome,
                                             _endereco,
                                             _telefone){
            habilitacao = _habilitacao;
        }
};

class Funcionario : public Usuario{
    public: 
        string matricula;

        Funcionario(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _matricula):Usuario(_cpf,
                                             _nome,
                                             _endereco,
                                             _telefone){
            matricula = _matricula;
        }

        Cliente cadastrarCliente(   string _cpf,
                                    string _nome,
                                    string _endereco,
                                    string _telefone,
                                    string _habilitacao){
            
            Cliente novoCliente(_cpf,_nome,_endereco,_telefone,_habilitacao);

            return novoCliente;
        
        }

        void cadastrarCliente( ){

            //todo: solicitar dados via terminal
/*
            Cliente novoCliente(_cpf,_nome,_endereco,_telefone,_habilitacao);

            return novoCliente;
            */
            //Cliente cliente;

            
        
        }

        Funcionario cadastrarFuncionario(   string _cpf,
                                            string _nome,
                                            string _endereco,
                                            string _telefone,
                                            string _matricula){
            
            Funcionario novoFuncionario(_cpf,_nome,_endereco,_telefone,_matricula);

            return novoFuncionario;
        
        }
        
        Veiculo cadastrarVeiculo(   string _id,
                                    string _marca,
                                    string _modelo,
                                    int _anoFabricacao,
                                    float _precoPorDia){
            
            Veiculo novoVeiculo(_id,_marca,_modelo,_anoFabricacao,_precoPorDia);

            return novoVeiculo;
        
        }
};