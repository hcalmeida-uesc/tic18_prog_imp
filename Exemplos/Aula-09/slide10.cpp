#include <iostream>

using namespace std;

int main(){
    char data[11];

    cout << "Informe uma data no formato dd/mm/aaaa " << endl;
    cin.getline(data,11);

    cout << data << endl;
    
    /*
        for(int i=0; data[i] != '\0'; i++){
        if(data[i] != '/'){
            cout << data[i];
        }else{
            cout << endl;
        }
    }
    */

    cout << data[0] << data[1] << endl;
    cout << data[3] << data[4] << endl;
    cout << data[6] << data[7] << data[8] << data[9] <<endl;

    return 0;
}