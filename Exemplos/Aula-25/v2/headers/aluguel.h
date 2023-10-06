#ifndef ALUGUEL_H
#define ALUGUEL_H

#include <iostream>
#include "cliente.h"
#include "veiculo.h"
#include "utilidades.h"
#include "funcionario.h"


using namespace std;

class Aluguel{
    public:
        string identificador;
        Veiculo *veiculo;
        Cliente *cliente;
        Funcionario *funcionario;
        struct tm *dataInicio;
        struct tm *dataTermino;
        struct tm *dataDevolucao;
        float desconto;
        float adicional;

        Aluguel(
            Cliente *_cliente,
            Funcionario *_funcionario,
            Veiculo *_veiculo,
            struct tm *_dataInicio,
            struct tm *_dataTermino
        );

        float CalcularValorFinal();
};

#endif