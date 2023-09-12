#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
};

typedef unsigned long long int intLongo;

int main(){
    Point p1;
    p1.x = 10;
    p1.y = 20;

    intLongo x;

    Point p2 = {5,15};

    return 0;
}