#include <iostream> 
using namespace std;

int main(void) 
{
    // true e false são objetos booleanos
    bool isNumber = true;  // definindo variáveis booleanas
    bool isPositive = true, isNegative = false;
    bool condition; 
    condition = (isNumber && isPositive); // operador lógico &&
    bool isEven, isOdd;
    isEven = 4 % 2 == 0; // operador de resto %
    isOdd = 4 % 2;
    cout << "isNumber = " << isNumber << endl;
    cout << "isPositive = " << isPositive << endl;
    cout << "isNegative = " << isNegative << endl;
    return 0;
}
