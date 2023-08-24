#include <iostream> 
using namespace std;

int main(void) 
{
    cout << "Qual a sua idade?: ";
    int idade;      // idade é uma variável de tipo inteiro
    cin >> idade;   // lendo um inteiro da entrada padrão
    cout << "Você tem " << idade << " anos.\n";
    return 0; 
}

