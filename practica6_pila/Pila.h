/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
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
