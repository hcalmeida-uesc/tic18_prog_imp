#include <iostream> 
using namespace std;

int main(void) 
{
    double x = 3.14, y, z;
    cout << "x = " << x << endl;
    y = x + 1.0;  //operador de adição
    cout << "y = x + 1.0 = " << y << endl;
    z = 7.0 - x;  //operador de subtração
    cout << "z = 7.0 - x = " << z << endl;
    x = x * -2.0;  //operador de multiplicação, operador unário -
    cout << "x = x * -2.0 = " << x << endl; 
    y = y / 2.0;  //operador de divisão real
    cout << "y = y / 2.0 = " << y << endl;  
    y = 5 / 2; //operador de divisão inteira
    cout << "y = 5 / 2 = " << y << endl;
    x = ++x + 2 * --y - z / 4.3 + 6.1 * 3.2;  //ordem de precedência dos operadores
    cout << "x = ++x + 2 * --y - z / 4.3 + 6.1 * 3.2 = " << x << endl;
    x = (++x + 2) * (--y - z) / ((4.3 + 6.1) * 3.2);  //usando parenteses
    cout << "x = ++(x + 2) * (--y - z) / ((4.3 + 6.1) * 3.2) = " << x << endl;
    return 0; 
}
