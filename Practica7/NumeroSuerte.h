#ifndef NUMEROSUERTE_H
#define NUMEROSUERTE_H

#include <iostream>

using namespace std;

class NumeroSuerte
{
    public:
        NumeroSuerte(int = 0);
        void establecerposicion(int);
        int obtenerposicion() const;
        void imprimir_registro();
        ~NumeroSuerte();
    private:
        int posicion;
};

#endif // NUMEROSUERTE_H
