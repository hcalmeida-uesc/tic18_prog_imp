#include <iostream>
#include <ctime>
#include <regex>

using namespace std;

class Pass{
    static string mask;

    public:
        static string getMask(){
            return mask;
        }

        static bool isStrong(string pass){
            return (regex_match(pass,regex(Pass::getMask())));
        }

        static string generatePass(){
            int length = 8 + rand() % 8;
            string pass;

            for(int i=0; i < length; i++){
                char t = 97 + rand() % (122-97+1);
                //cout << t << " - " << int(t) << endl;
                pass += t;
            }

            pass.at(rand() % length) = 48 + rand() % (57-48+1);
            pass.at(rand() % length) = 65 + rand() % (90-65+1);
            pass.at(rand() % length) = '@';

            return pass;
        }

};

string Pass::mask = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$";

int main(){
    string strBuff = "";
    string pass;
    
    srand(time(nullptr));

    while(strBuff != "-1"){
        getline(cin >> ws, strBuff);

        pass = Pass::generatePass();
 
        cout << pass << endl;

        if(Pass::isStrong(pass))
            cout << "Senha forte!" << endl;
        else
            cout << "Senha fraca!" << endl;
    }

    return 0;
}