#include <iostream>
#include <ctime>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

class Utilidades{
    public:

    static int diferencaEmDiasEntreDatas(struct tm * data1, struct tm * data2){
        time_t timestamp1 = mktime(data1);
        time_t timestamp2 = mktime(data2);

        // Calcule a diferença em segundos
        double diferenca_segundos = difftime(timestamp2, timestamp1);

        // Converta a diferença em segundos para dias
        return diferenca_segundos / (60 * 60 * 24);
    }

    static void imprimirData(struct tm *data){
        if(data != nullptr){
            cout << data->tm_mday << "/";
            cout << data->tm_mon+1 << "/";
            cout << data->tm_year+1900 << " - ";
            cout << data->tm_hour << ":";
            cout << data->tm_min << endl;
        }
        else
            cout << "Data inválida" << endl;
    }
};

class Usuario{
    public:
        string cpf;
        string nome;
        string endereco;
        string telefone;

        Usuario(string _cpf,
                string _nome,
                string _endereco,
                string _telefone){
            
            cpf = _cpf;
            nome = _nome;
            endereco = _endereco;
            telefone = _telefone;
        }
};

class Cliente : public Usuario{
    public:
        string habilitacao;

        //Cliente():Usuario("","","",""){}
        
        Cliente(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _habilitacao):Usuario(_cpf,
                                             _nome,
                                             _endereco,
                                             _telefone){
            habilitacao = _habilitacao;
        }
};

class Veiculo{
    public:
        string identificador;
        string marca;
        string modelo;
        int anoFabricacao;
        float precoPorDia;

        Veiculo(string _identificador,
                string _marca,
                string _modelo,
                int _anoFabricacao,
                float _precoPorDia){
            identificador = _identificador;
            marca = _marca;
            modelo = _modelo;
            anoFabricacao = _anoFabricacao;
            precoPorDia = _precoPorDia;
        }

        void buzinar(){
            std::cout << "bi bi" << endl;
        }
};

class Aluguel;

class Funcionario : public Usuario{
    public: 
        string matricula;

        Funcionario(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _matricula):Usuario(_cpf,
                                             _nome,
                                             _endereco,
                                             _telefone){
            matricula = _matricula;
        }

        Cliente cadastrarCliente(   string _cpf,
                                    string _nome,
                                    string _endereco,
                                    string _telefone,
                                    string _habilitacao){
            
            Cliente novoCliente(_cpf,_nome,_endereco,_telefone,_habilitacao);

            return novoCliente;
        
        }

        Funcionario cadastrarFuncionario(   string _cpf,
                                            string _nome,
                                            string _endereco,
                                            string _telefone,
                                            string _matricula){
            
            Funcionario novoFuncionario(_cpf,_nome,_endereco,_telefone,_matricula);

            return novoFuncionario;
        
        }
        
        Veiculo cadastrarVeiculo(   string _id,
                                    string _marca,
                                    string _modelo,
                                    int _anoFabricacao,
                                    float _precoPorDia){
            
            Veiculo novoVeiculo(_id,_marca,_modelo,_anoFabricacao,_precoPorDia);

            return novoVeiculo;
        
        }

        Aluguel AlugarVeiculo( //protótipo do método
            Cliente *_cliente,
            Funcionario *_funcionario,
            Veiculo *_veiculo,
            struct tm *_dataInicio,
            struct tm *_dataTermino
        );
};

class Aluguel{
    public:
        string identificador;
        Veiculo *veiculo;
        Cliente *cliente;
        Funcionario *funcionario;
        struct tm *dataInicio;
        struct tm *dataTermino;
        struct tm *dataDevolucao;
        float desconto;
        float adicional;

        Aluguel(
            Cliente *_cliente,
            Funcionario *_funcionario,
            Veiculo *_veiculo,
            struct tm *_dataInicio,
            struct tm *_dataTermino
        ){
            cliente = _cliente;
            veiculo = _veiculo;
            funcionario = _funcionario;
            dataInicio = _dataInicio;
            dataTermino = _dataTermino;
            dataDevolucao = nullptr;
            identificador = to_string(dataInicio->tm_year+1900)+"-"+cliente->cpf+"-"+veiculo->identificador;
        }

        float CalcularValorFinal(){
            int quantidadeDias;

            //todo1: verificar se veiculo foi devolvido
            if(dataDevolucao != nullptr){
                quantidadeDias = Utilidades::diferencaEmDiasEntreDatas(dataInicio,dataDevolucao);
                return veiculo->precoPorDia * quantidadeDias;
            }
            return 0;
        }
};

//definição do método
Aluguel Funcionario::AlugarVeiculo(Cliente *_cliente, Funcionario *_funcionario, Veiculo *_veiculo, struct tm *_dataInicio, struct tm *_dataTermino){

    Aluguel novoAluguel(_cliente, _funcionario, _veiculo, _dataInicio, _dataTermino);

    return novoAluguel;
}

class BancoDeDados{
    public:
        static void salvarDados(string arquivoNome, vector<string> dados){
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

        static vector<string> recuperarDados(string arquivoNome){
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

        static void clientesParaArquivo(string arquivoNome,vector<Cliente> clientes){
            vector<string> dados;

            for(Cliente cli : clientes){
                dados.push_back(cli.cpf);
                dados.push_back(cli.nome);
                dados.push_back(cli.endereco);
                dados.push_back(cli.telefone);
                dados.push_back(cli.habilitacao);
            }

            salvarDados(arquivoNome,dados);
        }

        static vector<Cliente> arquivoParaClientes(string arquivoNome){
            vector<string> dados = recuperarDados(arquivoNome);

            vector<Cliente> clientes;

            for(int i=0; i<dados.size()-1;i+=5){
                Cliente cli(
                    dados.at(i),
                    dados.at(i+1),
                    dados.at(i+2),
                    dados.at(i+3),
                    dados.at(i+4)
                );
                
                clientes.push_back(cli);
            }

            return clientes;
        }

        static void funcionariosParaArquivo(string arquivoNome,vector<Funcionario> funcionarios){
            vector<string> dados;

            for(Funcionario func : funcionarios){
                dados.push_back(func.cpf);
                dados.push_back(func.nome);
                dados.push_back(func.endereco);
                dados.push_back(func.telefone);
                dados.push_back(func.matricula);
            }

            salvarDados(arquivoNome,dados);
        }

        static vector<Funcionario> arquivoParaFuncionarios(string arquivoNome){
            vector<string> dados = recuperarDados(arquivoNome);

            vector<Funcionario> funcionarios;

            for(int i=0; i<dados.size()-1;i+=5){
                Funcionario func(
                            dados.at(i),
                            dados.at(i+1),
                            dados.at(i+2),
                            dados.at(i+3),
                            dados.at(i+4)
                        );
                funcionarios.push_back(func);
            }

            return funcionarios;
        }

        static void veiculosParaArquivo(string arquivoNome,vector<Veiculo> veiculos){
            vector<string> dados;

            for(Veiculo veiculo : veiculos){
                dados.push_back(veiculo.identificador);
                dados.push_back(veiculo.marca);
                dados.push_back(veiculo.modelo);
                dados.push_back(to_string(veiculo.anoFabricacao));
                dados.push_back(to_string(veiculo.precoPorDia));
            }

            salvarDados(arquivoNome,dados);
        }

        static vector<Veiculo> arquivoParaVeiculos(string arquivoNome){
            vector<string> dados = recuperarDados(arquivoNome);

            vector<Veiculo> veiculos;

            for(int i=0; i<dados.size()-1;i+=5){
                Veiculo veiculo(
                            dados.at(i),
                            dados.at(i+1),
                            dados.at(i+2),
                            stoi(dados.at(i+3)),
                            stof(dados.at(i+4))
                        );
                veiculos.push_back(veiculo);
            }

            return veiculos;
        }
};

int main(){
    
    time_t rawtime;
    struct tm *timeinfo, time2;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    memcpy(&time2, timeinfo, sizeof(time2));

    time2.tm_mday = 8;


    
    Funcionario func1("12234455","Ulian","Ilheus","454564","123456");

    vector<Funcionario> bancoFuncionarios;

    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000011","Teste1","Bahia","73333333","000001"));
    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000012","Teste2","Bahia","73333333","000002"));
    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000013","Teste3","Bahia","73333333","000003"));
    bancoFuncionarios.push_back(func1.cadastrarFuncionario("00000000014","Teste4","Bahia","73333333","000004"));

    BancoDeDados::funcionariosParaArquivo("funcionarios.txt",bancoFuncionarios);

    vector<Cliente> bancoClientes;

    bancoClientes.push_back(func1.cadastrarCliente("00000000021","Hélder", "Itabuna","646746464","101010"));
    bancoClientes.push_back(func1.cadastrarCliente("00000000022","Ulian", "Salvador","646746464","111111"));
    bancoClientes.push_back(func1.cadastrarCliente("00000000023","Jéssica", "Ilhéus","646746464","121212"));
    bancoClientes.push_back(func1.cadastrarCliente("00000000024","Paulo", "Arábia","646746464","131313"));

    BancoDeDados::clientesParaArquivo("clientes.txt",bancoClientes);

    vector<Veiculo> bancoVeiculos;

    bancoVeiculos.push_back(func1.cadastrarVeiculo("OUP-4062","HONDA","CIVIC LXR",2014,100));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("JMV-6030","FORD","CORSA HATCH",2000,40));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("NPM-1030","FERRARI","F40 SPYDER",2015,10000));
    bancoVeiculos.push_back(func1.cadastrarVeiculo("OUP-6030","VOLKSWAGEM","FUSCA 1.6",1960,25));

    BancoDeDados::veiculosParaArquivo("veiculos.txt",bancoVeiculos);

    bancoVeiculos = BancoDeDados::arquivoParaVeiculos("veiculos.txt");

    Cliente clienteTeste = bancoClientes.at(0);
    Funcionario funcionarioTeste = bancoFuncionarios.at(0);
    Veiculo veiculoTeste = bancoVeiculos.at(0);
    Aluguel novoAluguel = funcionarioTeste.AlugarVeiculo(&clienteTeste,&funcionarioTeste,&veiculoTeste,timeinfo,&time2);

    cout << novoAluguel.identificador << endl;
    cout << "Data de Inicio:";
    Utilidades::imprimirData(novoAluguel.dataInicio);
    cout << "Data de Termino:";
    Utilidades::imprimirData(novoAluguel.dataTermino);
    cout << "Data de Devolucao:";
    Utilidades::imprimirData(novoAluguel.dataDevolucao);
    cout << "Valor Final:";
    cout << novoAluguel.CalcularValorFinal() << endl;

    struct tm devolucaoTeste;

    memcpy(&devolucaoTeste, &time2, sizeof(struct tm));

    devolucaoTeste.tm_mday += 5;

    novoAluguel.dataDevolucao = &devolucaoTeste;

    cout << "Data de Devolucao:";
    Utilidades::imprimirData(novoAluguel.dataDevolucao);
    cout << "Quantidade de dias:";
    cout << Utilidades::diferencaEmDiasEntreDatas(novoAluguel.dataInicio,novoAluguel.dataDevolucao) << endl;
    cout << "Preço do veiculo por dia:";
    cout << novoAluguel.veiculo->precoPorDia << endl;
    cout << "Valor Final:";
    cout << novoAluguel.CalcularValorFinal() << endl;
}