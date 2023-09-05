#include <iostream>

using namespace std;

int main(){
    char c[2][2] = {{'a','b'},{'c','d'}};

    for(int lin=0; lin<2; lin++){
        for(int col=0; col<2; col++)
            cout << c[lin][col] << " ";
        cout << endl;
    }
  return 0;
}