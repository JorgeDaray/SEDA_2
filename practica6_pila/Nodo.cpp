/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include "Nodo.h"
#include "Libro.h"
#include <iostream>

using namespace std;

Nodo::Nodo()
{
    Datos.establecernombre("");
    Datos.establecerautor("");
    Datos.establecereditorial("");
    next = nullptr;
}//ctor

Nodo::~Nodo()
{

}//dtor
