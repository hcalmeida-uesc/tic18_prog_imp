#include <iostream>

using namespace std;

int main(){
    double r = 0.14;
    double p = 100000;
    double tx;
    double a;
    int ano,totalAnos = 10,i;

    for(ano=1; ano<=totalAnos; ano++){
        //a=p*(1+r))^ano
        for(tx=1,i=1;i<=ano;i++){
            tx *= (1+r);
        }
        a = p*tx;
        cout << "Valor no ano " << ano << " eh " << a << endl;
    }

    return 0;
}