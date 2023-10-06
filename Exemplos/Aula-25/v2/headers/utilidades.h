#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <ctime>

using namespace std;

class Utilidades{
    public:

    static int diferencaEmDiasEntreDatas(struct tm * data1, struct tm * data2);

    static void imprimirData(struct tm *data);
};

#endif