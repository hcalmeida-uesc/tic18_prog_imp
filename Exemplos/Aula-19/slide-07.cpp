#include <iostream>
#include <vector>

using namespace std;

class Ponto{
    double x,y;
    public:
        Ponto(double _x, double _y){
            x = _x;
            y =_y;
        }

        double getX(){
            return x;
        }

        double getY(){
            return y;
        }

        bool operator==(Ponto _p){
            return (x == _p.getX() && y == _p.getY());
        }

        void operator=(Ponto _p){
            x = _p.getX();
            y = _p.getY();
        }

        Ponto operator+(Ponto _p){
            Ponto p(x+_p.getX(),y+_p.getY());
            return p;
        }
};

class Poligono{
    public:
        vector<Ponto> pontos;
};

int main(){
    Ponto p1(2,3);
    Ponto p2(1,1);

    Ponto p3(1,2);

    p3 = p2+p3;

    if(p1 == p3){
        cout << "iguais" << endl;
    }else{
        cout << "diferentes" << endl;
    }

    return 0;
} 