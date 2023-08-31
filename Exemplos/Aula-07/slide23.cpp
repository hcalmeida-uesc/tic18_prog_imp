#include <iostream>

using namespace std;

int main(){
    int totalAlunos = 0;
    int nota;
    int somaNotas = 0;
    double mediaNotas = 0.0;
    char continuar;

    do{
        do{
            totalAlunos++;
            cout << "Digite a nota do aluno " << totalAlunos << endl;
            cin >> nota;
            if(nota >= 0 && nota <= 100){
                somaNotas += nota;
            }else{
                cout << "Nota errada" << endl;
            }
        }
        while(nota < 0 || nota >100);
        
        cout << "Deseja prosseguir (s/n)? " << endl;
        cin >> continuar;
    }while(continuar != 'n' && continuar != 'N');

    mediaNotas = somaNotas / totalAlunos;

    cout << "A quantidade de alunos foi " << totalAlunos << endl;
    cout << "A media da turma foi " << mediaNotas << endl;

    return 0;
}