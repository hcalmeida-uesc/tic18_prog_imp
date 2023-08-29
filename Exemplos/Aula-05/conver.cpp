#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    int a, b, c;
    double x, y, z;

    cout << "Simulando o lançamento de uma moeda" << endl;
    a = rand()%2;
    cout << "Moeda: " << (a == 0 ? "Cara" : "Coroa") << endl;
    cout << "Simulando o lançamento de um dado de 6 varas" << endl;
    b = 1 + rand()%6;
    cout << "Dado: "<< b << endl;
    cout << "Gerando um caractere aleatório" << endl;
    c = 'a' + rand()%('z' - 'a'); // cast implícito
    cout << "Caractere: " << static_cast<char>(c) << endl; // cast explícito 
    cout << "Gerando um valor de ponto flutuante aleatório entre 0 e 1" << endl;
    x = (double)rand()/RAND_MAX; // cast explícito
    cout << "x = " << x << endl;
    cout << "Gerando um valor de ponto flutuante aleatório entre 0 e 5" << endl;
    y = (rand()/RAND_MAX)*5.0; // cast implícito, não funciona, sempre retorna 0
    cout << "y = " << y << endl;
    y = (1.0*rand()/RAND_MAX)*5; // cast implícito, funciona
    cout << "y = " << y << endl;
    cout << "Gerando um valor de ponto flutuante aleatório entre -5 e 5" << endl;
    z = -5 + (1.0*rand()/RAND_MAX)*10.0; // cast implícito, 
    cout << "z = " << z << endl;
    return 0;
}
