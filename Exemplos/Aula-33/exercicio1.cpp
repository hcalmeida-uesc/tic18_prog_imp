#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// interface
class Desenhavel{
    public:
        virtual void desenhar() = 0;
};

class Forma{
    public:

        virtual double area(){
            return 0.0;
        }
};

class Circulo : public Forma, public Desenhavel{
    public:
        double raio;

        void desenhar() override{
            cout << "Raio = " << raio << endl;
        }

        double area() override{
            return M_PI*raio*raio;
        }
};

class Retangulo : public Forma{
    public:
        double base, altura;

        double area() override{
            return base*altura;
        }
};


int main(){
    vector<Forma*> listFormas;
    
    
    cout << "Elementos diretamente dos objetos: " << endl;
    Circulo *circulo = new Circulo();
    circulo->raio = 2;
    cout << circulo->area() << endl;

    listFormas.push_back(circulo);

    Retangulo *retangulo = new Retangulo();
    retangulo->base = 16;
    retangulo->altura = 9;
    cout << retangulo->area() << endl;

    listFormas.push_back(retangulo);

    cout << "Elementos do vector: " << endl;
    for(Forma* el : listFormas){
        cout << el->area() << endl;
    }

    cout << "Elementos imprimiveis: " << endl;
    Desenhavel *formasDesenho;
    formasDesenho = circulo;
    formasDesenho->desenhar();

    // isso não é possível!
    //formasDesenho = retangulo;
    //formasDesenho->desenhar();

    return 0;
}