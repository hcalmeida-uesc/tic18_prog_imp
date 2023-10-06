#include "headers/utilidades.h"
#include <iostream>

using namespace std;

int Utilidades::diferencaEmDiasEntreDatas(struct tm * data1, struct tm * data2){
    time_t timestamp1 = mktime(data1);
    time_t timestamp2 = mktime(data2);

    // Calcule a diferença em segundos
    double diferenca_segundos = difftime(timestamp2, timestamp1);

    // Converta a diferença em segundos para dias
    return diferenca_segundos / (60 * 60 * 24);
}

void Utilidades::imprimirData(struct tm *data){
    if(data != nullptr){
        cout << data->tm_mday << "/";
        cout << data->tm_mon+1 << "/";
        cout << data->tm_year+1900 << " - ";
        cout << data->tm_hour << ":";
        cout << data->tm_min << endl;
    }
    else
        cout << "Data inválida" << endl;
}