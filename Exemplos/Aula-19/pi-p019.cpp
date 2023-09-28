#include <iostream>
#include <vector>

using namespace std;

class ItemSet{
    private:
        
    public:
        vector<string> itens;

        vector<string> getItens(){
            return itens;
        }
        void inserir(string _item){
            if(ProcItem(_item) == -1)
                itens.push_back(_item);
            else
                cout << "Item encontrado no conjunto" << endl;
        }
        void excluir(string _item){
            int posicao = ProcItem(_item);
            if(posicao > -1){
                itens.at(posicao).erase();
            }
            else
                cout << "Não encontrado" << endl;
        }

        int ProcItem(string _item){
            int i = 0;
            for(auto it=itens.begin();
             it!=itens.end();
             it++,i++){
                if(*it == _item){
                    return i;
                }

            }

            return -1;
        }

        void print(){
            for(auto it=itens.begin();
             it!=itens.end();
             it++){
                cout << *it << endl;

    }
        }
};

int main(){
    ItemSet conjunto;

    conjunto.inserir("Item A");
    conjunto.inserir("Item B");
    conjunto.inserir("Item C");

    conjunto.print();

    cout << conjunto.ProcItem("Item D") << endl;

    conjunto.excluir("Item B");

    conjunto.print();

    conjunto.inserir("Item A");
    return 0;
}