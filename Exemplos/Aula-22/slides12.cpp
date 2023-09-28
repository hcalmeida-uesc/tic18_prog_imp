#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BancoDeDados{
    inline static string arquivoNome = "exemplo.txt";
    public:
        static void salvarDados(vector<string> dados){
            ofstream arquivo;
            
            vector<string>::iterator it;
            arquivo.open(arquivoNome,ios_base::out);
            
            if (arquivo.is_open()) {
                for(it = dados.begin(); it != dados.end(); it++){
                    arquivo << *it << endl;
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }

        static vector<string> recuperarDados(){
            ifstream arquivo;
            vector<string> dados;
            arquivo.open(arquivoNome,ios_base::in);
            
            if (arquivo.is_open()) {
                string linha;
            while (arquivo.eof() == false) {
                    getline(arquivo, linha);
                    dados.push_back(linha);
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }

            return dados;
        }

};

int main(){
    vector<string> dadosParaArquivo;
    vector<string> dadosDoArquivo;

    dadosParaArquivo.push_back("Escrevendo no arquivo.");

    for(int i=0; i < 10; i++)
        dadosParaArquivo.push_back(to_string(i));

    BancoDeDados::salvarDados(dadosParaArquivo);

    dadosDoArquivo = BancoDeDados::recuperarDados();
    
    for(auto it = dadosDoArquivo.begin();
        it != dadosDoArquivo.end();
        it++){
        
        cout << *it << endl;
    }

    return 0;
}

