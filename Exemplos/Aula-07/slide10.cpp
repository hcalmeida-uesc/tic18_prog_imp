#include <iostream>
using namespace std;

int main() {
    int nota;

    cout << "Digite a nota (0-10): ";
    cin >> nota;

    if (nota >= 0 && nota <= 10) {
        if (nota >= 9) {
            cout << "Conceito A" << endl;
        } else if (nota >= 7) {
            cout << "Conceito B" << endl;
        } else if (nota >= 5) {
            cout << "Conceito C" << endl;
        } else if (nota >= 3) {
            cout << "Conceito D" << endl;
        } else {
            cout << "Conceito F" << endl;
        }
    } else {
        cout << "Nota invalida. Digite um valor entre 0 e 10." << endl;
    }

    return 0;
}
