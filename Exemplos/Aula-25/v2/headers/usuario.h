#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

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
                string _telefone);
            
};
#endif