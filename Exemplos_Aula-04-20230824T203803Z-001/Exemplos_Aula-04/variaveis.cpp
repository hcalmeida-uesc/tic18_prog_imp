#include <iostream> 
using namespace std;

int main(void) 
{
    // Podemos inicializar uma variável de várias formas
    int valor_1; // valor_1 é inicializado com um valor indefinido
    int valor_2 = 0; // valor_2 é inicializado com 0
    int valor_3 = {0}; // valor_3 é inicializado com 0
    int valor_4(0); // valor_5 é inicializado com 0
    int valor_5 = int(); // valor_6 é inicializado com 0
    
    cout << "valor_1 = " << valor_1 << endl;
    cout << "valor_2 = " << valor_2 << endl;
    cout << "valor_3 = " << valor_3 << endl;
    cout << "valor_4 = " << valor_4 << endl;
    cout << "valor_5 = " << valor_5 << endl;

    return 0; 
}