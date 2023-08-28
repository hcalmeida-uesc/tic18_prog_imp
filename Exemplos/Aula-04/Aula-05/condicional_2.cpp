#include <iostream>
using namespace std;

int main(void)
{
    int val1, val2, max;
    cout << "Entre com um valor inteiro: ";
    cin >> val1;
    cout << "Entre com outro valor inteiro: ";
    cin >> val2;
    max = val1 > val2 ? val1 : val2;
    cout << "O maior valor fornecido foi: " << max << endl;
    return 0;
}
