#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
#include "NumeroSuerte.h"
#include <iostream>
#include <fstream>

/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */

using namespace std;

class Cola
{
    public:
        Cola();
        void insertar(NumeroSuerte);
        NumeroSuerte borrar();
        void mostrar();
        Nodo *frente;
        Nodo *raiz;
        ~Cola();
    private:
};

#endif // COLA_H
