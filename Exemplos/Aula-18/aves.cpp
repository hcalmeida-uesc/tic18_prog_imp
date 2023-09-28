#include <iostream>

using namespace std;

class Ave{

    private:
        string especie;

    public:
        string getEspecie(){
            return especie;
        }

        void setEspecie(string _especie){
            especie = _especie;
        }

};

int main(){
    Ave cobaia;
    string strBuffer;

    getline(cin >> ws, strBuffer);
    cobaia.setEspecie(strBuffer);

    return 0;
}