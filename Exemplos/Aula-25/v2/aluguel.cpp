#include "headers/aluguel.h"

Aluguel::Aluguel(Cliente *_cliente, Funcionario *_funcionario, Veiculo *_veiculo, struct tm *_dataInicio, struct tm *_dataTermino){
    cliente = _cliente;
    veiculo = _veiculo;
    funcionario = _funcionario;
    dataInicio = _dataInicio;
    dataTermino = _dataTermino;
    dataDevolucao = nullptr;
    identificador = to_string(dataInicio->tm_year+1900)+"-"+cliente->cpf+"-"+veiculo->identificador;
}

float Aluguel::CalcularValorFinal(){
    int quantidadeDias;

    //todo1: verificar se veiculo foi devolvido
    if(dataDevolucao != nullptr){
        quantidadeDias = Utilidades::diferencaEmDiasEntreDatas(dataInicio,dataDevolucao);
        return veiculo->precoPorDia * quantidadeDias;
    }
    return 0;
}