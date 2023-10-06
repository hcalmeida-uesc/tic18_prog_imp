#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include "cliente.h"
#include "veiculo.h"

using namespace std;

class Aluguel;

class Funcionario : public Usuario{
    public: 
        string matricula;

        Funcionario(
            string _cpf,
            string _nome,
            string _endereco,
            string _telefone,
            string _matricula
        );

        Cliente cadastrarCliente(
            string _cpf,
            string _nome,
            string _endereco,
            string _telefone,
            string _habilitacao
        );

        Funcionario cadastrarFuncionario(   
            string _cpf,
            string _nome,
            string _endereco,
            string _telefone,
            string _matricula
        );

        Veiculo cadastrarVeiculo(
            string _id,
            string _marca,
            string _modelo,
            int _anoFabricacao,
            float _precoPorDia
        );

        Aluguel AlugarVeiculo(
            Cliente *_cliente,
            Funcionario *_funcionario,
            Veiculo *_veiculo,
            struct tm *_dataInicio,
            struct tm *_dataTermino
        );
};

#endif