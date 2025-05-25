#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Libro.h"
#include <iostream>
#include <fstream>

using namespace std;

class Pila
{
    public:
        Pila();
        void push(Libro);
        void pop();
        void mostrar();
        ~Pila();
    private:
        Nodo *top;
};

#endif // PILA_H
