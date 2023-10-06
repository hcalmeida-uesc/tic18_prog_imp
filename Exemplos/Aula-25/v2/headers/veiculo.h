#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>

using namespace std;

class Veiculo{
    public:
        string identificador;
        string marca;
        string modelo;
        int anoFabricacao;
        float precoPorDia;

        Veiculo(string _identificador,
                string _marca,
                string _modelo,
                int _anoFabricacao,
                float _precoPorDia);

        void buzinar();
};

#endif