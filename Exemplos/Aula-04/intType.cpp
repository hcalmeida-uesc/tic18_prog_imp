#include <iostream> 
using namespace std;

int main(void) 
{ 
    int quantidade; // quantidade é uma variável de tipo inteiro
    cout << "Quantos alunos há na turma?: ";
    cin >> quantidade; // lendo um inteiro da entrada padrão
    cout << "Há " << quantidade << " alunos na turma.\n";
    cout << "O tipo short int ocupa " << sizeof(short int) << " bytes na memória.\n";
    cout << "O tipo int ocupa " << sizeof(int) << " bytes na memória.\n";  
    cout << "O tipo long int ocupa " << sizeof(long int) << " bytes na memória.\n";
    cout << "O tipo long long int ocupa " << sizeof(long long int) << " bytes na memória.\n"; 
    unsigned short int idade  = 20; // o tipo unsigned short int só armazena valores positivos
    cout << "A idade é: " << idade << endl;
    int valHexa = 0x1A; // o prefixo 0x indica que o valor é hexadecimal
    cout << "O valor de valHexa: " << valHexa << " ou " << hex << valHexa << dec;
    cout << " em hexadecimal." << endl;
    long int valOctal = 032; // o prefixo 0 indica que o valor é octal
    cout << "O valor de valOctal: " << valOctal << " ou " << oct << valOctal << dec;
    cout << " em octal." << endl;  
    return 0;  
}

