#include <iostream>
#include <vector>

using namespace std;

class Cliente{
    public:
        string nome;
        string cpf;
};

class Dependente{
    public:
        string nome;
        Cliente *responsavel;
};

class Evento{
    public:
        int duracao;

        Evento(int _duracao){
            duracao = _duracao;
        }

        virtual ~Evento() = default;
};

class Roteiro : public Evento{
    public:
        string atividade;
        Roteiro(int d, string _atividade):Evento(d){
            atividade = _atividade;
        }
};

class Deslocamento : public Evento{
    public:
        string de;
        string para;
        Deslocamento(int d, string _de, string _para):Evento(d){
            de = _de;
            para = _para;
        }
};

class Pernoite : public Evento{
    public:
        string local;
        Pernoite(int d, string _local):Evento(d){
            local = _local;
        }
};

class Pacote{
    public:
        vector<Evento*> eventos;
};

class Reserva{
    public:
        Cliente *cliente;
        Pacote *pacote;
};

class App{
    public:

        Evento* criarEvento(string tipo,int duracao, string param1,string param2=""){
            
            if(tipo == "roteiro")
                return new Roteiro(duracao,param1);
            else
            if(tipo == "deslocamento")
                return new Deslocamento(duracao,param1,param2);
            else
                return new Pernoite(duracao,param1);

        }
};

int main(){

    App app;

    Roteiro* r1 = dynamic_cast<Roteiro*>(app.criarEvento("roteiro",3,"Comer Jaca"));
    Deslocamento* d1 = dynamic_cast<Deslocamento*>(app.criarEvento("deslocamento",2,"Itabuna","Ilhéus"));
    Pernoite* p1 = dynamic_cast<Pernoite*>(app.criarEvento("pernoite",8,"Praia"));

    cout << r1->atividade << " - " << r1->duracao << endl;
    cout << d1->de << " - " << d1->para << " - " << d1->duracao << endl;
    cout << p1->local << " - " << p1->duracao << endl;

    return 0;
}