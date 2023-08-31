#include <iostream>

using namespace std;

int main(){
    int totalAlunos = 2;
    int alunos = 1;
    int nota;
    int somaNotas = 0;
    double mediaNotas = 0.0;

    while(alunos <= totalAlunos){
        cout << "Digite a nota do aluno " << alunos << endl;
        cin >> nota;
        if(nota >= 0 && nota <= 100){
            somaNotas += nota;
            alunos++;
        }else{
            cout << "Nota errada" << endl;
        }
    }

    mediaNotas /= totalAlunos;

    cout << "A media da turma foi " << mediaNotas << endl;

    return 0;
}