#include <iostream>
#include <ctime>

using namespace std;

void maxmin(int vetor[], int n, int &maximo, int &minimo){
    maximo = minimo = vetor[0];
    for(int i=1; i<n; i++){
        if(vetor[i] > maximo)  maximo = vetor[i];
        else
        if(vetor[i] < minimo)  minimo = vetor[i];
    }
}

void print_vetor(int vetor[], int n){
    cout << "Vetor [i] = valor " << endl;
    for(int i=0; i<n; i++){
        cout << "[" << i << "] = " << vetor[i] << endl;
    }
}

int main(){
    int tamanhoVetor = 10;
    int maximo;
    int minimo;
    int vetorTeste[tamanhoVetor] = {0};

    srand(time(nullptr));
    
    for(int i=0; i<tamanhoVetor; i++){
        vetorTeste[i] = rand()%43;
    }

    maxmin(vetorTeste,tamanhoVetor,maximo,minimo);

    print_vetor(vetorTeste,tamanhoVetor);

    cout << endl;
    cout << "maximo " << maximo << endl;
    cout << "minimo " << minimo << endl;

    return 0;
}