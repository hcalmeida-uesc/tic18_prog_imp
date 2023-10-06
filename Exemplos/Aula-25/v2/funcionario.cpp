#include "headers/funcionario.h"
#include "headers/aluguel.h"

Funcionario::Funcionario(string _cpf, string _nome, string _endereco, string _telefone,string _matricula):Usuario(_cpf, _nome, _endereco, _telefone){
    matricula = _matricula;
}

Cliente Funcionario::cadastrarCliente(string _cpf, string _nome, string _endereco, string _telefone, string _habilitacao){

    Cliente novoCliente(_cpf,_nome,_endereco,_telefone,_habilitacao);

    return novoCliente;

}
/*
        void cadastrarCliente( ){

            //todo: solicitar dados via terminal

            Cliente novoCliente(_cpf,_nome,_endereco,_telefone,_habilitacao);

            return novoCliente;
            
            //Cliente cliente;

            
        
        }*/

Funcionario Funcionario::cadastrarFuncionario(string _cpf, string _nome, string _endereco, string _telefone, string _matricula){

    Funcionario novoFuncionario(_cpf,_nome,_endereco,_telefone,_matricula);

    return novoFuncionario;

}

Veiculo Funcionario::cadastrarVeiculo(   string _id,
                            string _marca,
                            string _modelo,
                            int _anoFabricacao,
                            float _precoPorDia){
    
    Veiculo novoVeiculo(_id,_marca,_modelo,_anoFabricacao,_precoPorDia);

    return novoVeiculo;

}

Aluguel Funcionario::AlugarVeiculo(Cliente *_cliente, Funcionario *_funcionario, Veiculo *_veiculo, struct tm *_dataInicio, struct tm *_dataTermino){

    Aluguel novoAluguel(_cliente, _funcionario, _veiculo, _dataInicio, _dataTermino);

    return novoAluguel;
}
        
