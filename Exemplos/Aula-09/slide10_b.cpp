#include <iostream>
#include <string>
using namespace std;

int main(){
    char data[11];
    char diaStr[3],mesStr[3],anoStr[5];
    int diaInt,mesInt,anoInt;

    cout << "Informe uma data no formato dd/mm/aaaa " << endl;
    cin.getline(data,11);

    diaStr[0] = data[0];
    diaStr[1] = data[1];
    diaInt = stoi(diaStr);

    mesStr[0] = data[3];
    mesStr[1] = data[4];
    mesInt = stoi(mesStr);

    anoStr[0] = data[6];
    anoStr[1] = data[7];
    anoStr[2] = data[8];
    anoStr[3] = data[9];
    anoInt = stoi(anoStr);

    if( diaInt > 0 && diaInt < 32 &&
        mesInt > 0 && mesInt < 13 &&
        anoInt > 0
      ){
        cout << "A data " << data << " é válida!" << endl;
    }
    else{
        cout << "A data " << data << " é inválida!" << endl;
    }

    return 0;
}