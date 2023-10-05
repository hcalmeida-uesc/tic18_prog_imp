#include <iostream>
#include "veiculo.h"
#include "usuario.h"

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
        ){
            cliente = _cliente;
            veiculo = _veiculo;
            funcionario = _funcionario;
            dataInicio = _dataInicio;
            dataTermino = _dataTermino;
            dataDevolucao = nullptr;
        }

        float CalcularValorFinal(){
            int quantidadeDias;

            //todo1: verificar se veiculo foi devolvido
            if(dataDevolucao != nullptr){

                //todo2: quantidadeDias = dataDevolucao - dataInicio;

            }

            return veiculo->precoPorDia * quantidadeDias;
        }
};