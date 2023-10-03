#include <iostream>

using namespace std;

class Animal{
    private:
        string nome;
        int idade;
    public:
        Animal(string _nome, int _idade){
            nome = _nome;
            idade = _idade;
        }

        string getNome(){
            return nome;
        }

        int getIdade(){
            return idade;
        }

        void fazerSom();
};

class Cachorro : public Animal{
    public:
        Cachorro(string _nome, int _idade):
            Animal(_nome, _idade){}
        
        void fazerSom(){
            cout << "Au au";
        }

};

int main(){

    Cachorro sherlock("sherlock",5);
    cout << sherlock.getNome() << endl;
    sherlock.fazerSom();

    return 0;
}