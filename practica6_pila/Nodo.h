/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
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
