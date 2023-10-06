#include "headers/veiculo.h"

Veiculo::Veiculo(string _identificador, string _marca, string _modelo, int _anoFabricacao, float _precoPorDia){
    identificador = _identificador;
    marca = _marca;
    modelo = _modelo;
    anoFabricacao = _anoFabricacao;
    precoPorDia = _precoPorDia;
}

void Veiculo::buzinar(){
    cout << "bi bi" << endl;
}