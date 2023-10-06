#include "headers/cliente.h"

Cliente::Cliente(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _habilitacao):Usuario(_cpf,
                                             _nome,
                                             _endereco,
                                             _telefone){
            habilitacao = _habilitacao;
        }