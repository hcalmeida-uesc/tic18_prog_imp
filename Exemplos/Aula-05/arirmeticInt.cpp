#include <iostream> 
using namespace std;

int main(void) 
{
    int i = 0, j, k;
    cout << "i = " << i << endl;
    j = i + 1;  //operador de adição
    cout << "j = i + 1 = " << j << endl;
    k = 7 - i;  //operador de subtração
    cout << "k = 7 - i = " << k << endl;
    i = i * -2;  //operador de multiplicação, operador unário -
    cout << "i = i * -2 = " << i << endl;
    j = j / 2;  //operador de divisão
    cout << "j = j / 2 = " << j << endl;
    k = k % 2;  //operador de resto
    cout << "k = k % 2 = " << k << endl;
    cout << "Usando o operador decremento: " << endl;
    cout << "i = " << i << endl;
    cout << "i-- = " << i-- << endl;
    cout << "i = " << i << endl;
    cout << "--i = " << --i << endl;
    cout << "i = " << i << endl;
    cout << "Usando o operador incremento: " << endl;
    cout << "i = " << i << endl;
    cout << "i++ = " << i++ << endl;
    cout << "i = " << i << endl;
    cout << "++i = " << ++i << endl;
    cout << "i = " << i << endl;
    i = ++i + 2 * --j - k / 4 + 6 % 3;  //ordem de precedência dos operadores
    cout << "i = ++i + 2 * --j - k / 4 + 6 % 3 = " << i << endl;
    i = (++i + 2) * (--j - k) / ((4 + 6) % 3);  //usando parenteses
    cout << "i = ++(i + 2) * (--j - k) / ((4 + 6) % 3) = " << i << endl;
    return 0; 
}

