#include <iostream>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

bool dataValida(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2100) { return false; }
    if (mes < 1 || mes > 12) { return false; }
    int diasNoMes = 0;
    if (mes == 2) {
        diasNoMes = 
        (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } else {
        diasNoMes = 31;
    }
    if (dia < 1 || dia > diasNoMes) { return false; }

    return true;
}


int main(){
    struct Data data;
    data.dia = 15;
    data.mes = 8;
    data.ano = 2023;

    if(dataValida(data.dia,data.mes,data.ano)){
        cout << data.dia << "/";
        cout << data.mes << "/";
        cout << data.ano << endl;
    }
    else{
        cout << "Data inválida";
    }
    
    return 0;
}