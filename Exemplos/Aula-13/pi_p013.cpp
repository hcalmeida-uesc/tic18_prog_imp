#include <iostream>
#include <vector>

using namespace std;

struct Passagem{
    string  passageiroNome;
    string  passageiroCpf;
    int     passageiroIdade;

    int assento;
    string tipoViagem;

    int dataDia;
    int dataMes;
    int hora;
};

int main(){
    vector<Passagem> viagens;
    Passagem novaPassagem;

    bool continuar = true;
    string tempString;

    while(continuar){
        cout << "Informe o tipo de viagem (ida/volta) ";
        getline(cin, novaPassagem.tipoViagem);

        cout << "Informe o mes da viagem (1-12)";
        cin >> novaPassagem.dataMes;

        cout << "Informe o dia da viagem (1-30)";
        cin >> novaPassagem.dataDia;

        cout << "Informe a hora da viagem" << endl;
        cout << "(08,10,13,15,20) ";
        cin >> novaPassagem.hora;

        cout << "Informe o nome do passageiro ";
        getline(cin >> ws,novaPassagem.passageiroNome);
        
        cout << "Informe o cpf do passageiro ";
        getline(cin >> ws,novaPassagem.passageiroCpf);

        cout << "Informe a idade do passageiro ";
        cin >> novaPassagem.passageiroIdade;

        viagens.push_back(novaPassagem);
        //novaPassagem = {};

        cout << "Deseja vender mais uma passagem (s/n)? ";
        getline(cin >> ws,tempString);
        continuar = tempString == "s" ? true : false;
    }
    
    for(auto it = viagens.begin();
        it != viagens.end();
        it++){
            cout << (*it).passageiroNome;
        }

    return 0;
}