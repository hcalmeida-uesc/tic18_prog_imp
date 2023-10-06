#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "usuario.h"

using namespace std;

class Cliente : public Usuario{
    public:
        string habilitacao;
        
        Cliente(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _habilitacao);
};

#endif