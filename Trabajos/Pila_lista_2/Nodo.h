#ifndef NODO_H
#define NODO_H
#include "Libro.h"
#include <iostream>

using namespace std;

class Nodo
{
    public:
        Nodo();
        Libro Datos; //tipo objeto Datos de Libro
        Nodo *next;//Apuntador a siguiente
        ~Nodo();
    private:
};

#endif // NODO_H
