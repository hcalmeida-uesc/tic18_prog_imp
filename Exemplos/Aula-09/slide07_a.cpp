#include <iostream>


using namespace std;

#define N_ELEMENTOS 100
#define N_NOTAS_MAX 20

int main(){
    int elementos[N_ELEMENTOS] = {0};
    int frequencia[N_NOTAS_MAX] = {0};
    int numSorteado;

    srand(time(NULL));
    
    for(int i=0; i<N_ELEMENTOS; i++){
        numSorteado = 1 + rand()%N_NOTAS_MAX;
        elementos[i] = numSorteado;
        frequencia[numSorteado-1]++;
    }

    cout << "Elementos - Frequencia" << endl;
    
    for(int i=0; i<N_ELEMENTOS; i++){
        numSorteado = elementos[i];
        cout << "Elem. " << numSorteado << " - " << frequencia[numSorteado-1] << endl;
    }

    return 0;
}