#include <iostream>
#include "veiculo.h"
#include "usuario.h"

using namespace std;

class Aluguel{
    public:
        string identificador;
        Veiculo *veiculo;
        Veiculo *cliente;
        Funcionario *funcionario;
        tm dataInicio;
        tm dataTermino;
        tm dataDevolucao;
        float desconto;
        float adicional;
};