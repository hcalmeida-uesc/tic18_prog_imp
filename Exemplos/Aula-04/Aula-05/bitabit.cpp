#include <iostream> 
using namespace std;

int main(void) 
{
    unsigned char byteA, byteB, byteC;
    byteA = 255; // 11111111
    byteB = 0; // 00000000
    byteC = byteA & byteB; // 00000000
    cout << "byteA & byteB = " << (int)byteC << endl;
    byteC = byteA | byteB; // 11111111
    cout << "byteA | byteB = " << (int)byteC << endl;
    byteC = byteA >> 4; // 00001111
    cout << "byteA >> 4 = " << (int)byteC << endl;
    byteC = byteA << 4; // 11110000
    cout << "byteA << 4 = " << (int)byteC << endl;
    byteC = ~byteA; // 00000000
    cout << "~byteA = " << (int)byteC << endl;
    byteC = byteA ^ (byteA << 4); // 11111111 ^ 11110000 = 00001111
    cout << "byteA ^ (byteA << 4) = " << (int)byteC << endl;
    return 0; 
}