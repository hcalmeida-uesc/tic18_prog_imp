#include <iostream>

using namespace std;

int main(){
    double x,y,z,fx;

    cout << "Digite o valor de x ";
    cin >> x;

    cout << "Digite o valor de y ";
    cin >> y;

    fx = (5*x)+2;

 
/* primeira forma de fazer
    cout << ((y < fx) ? "Lado Direito" :"");
    cout << ((y == fx) ? "Na curva" : "");
    cout << ((y > fx) ? "Lado Esquerdo" : "");
*/
    cout << ((y < fx) ? "Lado Direito" :(y > fx) ? "Lado Esquerdo" : "Na curva") << endl;
    
    return 0;
}