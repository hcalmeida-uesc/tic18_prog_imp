#include <iostream>

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
                float _precoPorDia){
            identificador = _identificador;
            marca = _marca;
            modelo = _modelo;
            anoFabricacao = _anoFabricacao;
            precoPorDia = _precoPorDia;
        }

        void buzinar(){
            cout << "bi bi" << endl;
        }
};