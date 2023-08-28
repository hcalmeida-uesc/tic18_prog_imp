#include <iostream>
using namespace std;

int main(void)
{
    bool isTrue, isFalse;
    int a = 1, b = 2, c = 3, d = 4, e = -1;
    cout << "a = " << a << ", b = " << b
         << ", c = " << c << ", d = " << d << ", e = " << e << endl;
    isTrue = a > e; // maior que retorna true
    cout << "a > e is " << (isTrue ? "true":"false") << endl;
    isFalse = a > b; // maior que retorna false
    cout << "a > b is " << (isFalse ? "true":"false") << endl;
    isTrue = a < b; // menor que retorna true
    cout << "a < b is " << (isTrue ? "true":"false") << endl;
    isFalse = a < e; // menor que retorna false
    cout << "a < e is " << (isFalse ? "true":"false") << endl;
    isTrue = d >= 2 * b; // maior ou igual retorna true
    cout << "d >= 2 * b is " << (isTrue ? "true":"false") << endl;
    isFalse = d >= 2 * c; // maior ou igual retorna false
    cout << "d >= 2 * c is " << (isFalse ? "true":"false") << endl;
    isTrue = a <= 2 * b; // menor ou igual retorna true
    cout << "a <= 2 * b is " << (isTrue ? "true":"false") << endl; 
    isFalse = c <= 2 * a; // menor ou igual retorna false
    cout << "c <= 2 * a is " << (isFalse ? "true":"false") << endl;
    isTrue = 2*a == b; // igual retorna true
    cout << "2*a == b is " << (isTrue ? "true":"false") << endl;
    isFalse = b == c; // igual retorna false
    cout << "b == c is " << (isFalse ? "true":"false") << endl;
    isTrue = 2*a != c; // diferente retorna true
    cout << "2*a != c is " << (isTrue ? "true":"false") << endl;
    isFalse = 2*a != b; // diferente retorna false
    cout << "2*a != b is " << (isFalse ? "true":"false") << endl;
    return 0;
}
