#include <iostream>
#include <cmath>

using namespace std;

class Forma{
    public:
        double calcularArea();
};

class Retangulo : public Forma{
    private:
        double base,altura;
    public:
        Retangulo(double _base, double _altura){
            base = _base <= 0 ? 0 : _base;
            altura = _altura;
        }

        double calcularArea(){
            return base * altura;
        }
};

class Circulo : public Forma{
    private:
        double raio;
    public:
        Circulo(double _raio){
            raio = _raio <= 0 ? 0 : _raio;
        }

        double calcularArea(){
            return M_PI*raio*raio;
        }
};

int main(){
    Retangulo ret(2.0,3.0);
    Circulo circ(2.0);

    cout << ret.calcularArea() << endl;
    cout << circ.calcularArea() << endl;


    return 0;
}