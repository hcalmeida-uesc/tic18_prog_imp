#include <iostream>
using namespace std;

int main() {
    char operacao;
    double num1, num2;

    cout << "Digite a operacao (+, -, *, /): ";
    cin >> operacao;

    cout << "Digite dois numeros: ";
    cin >> num1 >> num2;

    switch (operacao) {
        case '+':
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Resultado: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Resultado: " << num1 / num2 << endl;
            } else {
                cout << "Erro: Divisao por zero." << endl;
            }
            break;
        default:
            cout << "Operacao invalida." << endl;
    }

    return 0;
}
