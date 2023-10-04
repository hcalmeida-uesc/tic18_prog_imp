#include <iostream>

using namespace std;

class Veiculo{
    public:
        string identificador;
        string marca;
        string modelo;
        int anoFabricacao;
        float precoPorDia;

        void buzinar(){
            cout << "bi bi" << endl;
        }
};