#include <iostream>
#include <cmath>

using namespace std;

struct Ponto{
    int x;
    int y;
};

double calculaDistancia(Ponto &a, Ponto &b){
    return sqrt(pow(a.x - b.x,2.0) + pow(a.y - b.y,2.0));
}


int main(){
    Ponto p1,p2;

    cin >> p1.x;
    cin >> p1.y;
    cin >> p2.x;
    cin >> p2.y;

    cout << calculaDistancia(p1,p2) << endl;
    
    return 0;
}