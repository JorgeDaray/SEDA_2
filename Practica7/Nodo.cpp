/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include "Nodo.h"
#include "NumeroSuerte.h"
#include <iostream>

using namespace std;

Nodo::Nodo()
{
    Datos.establecerposicion(0);
    next = nullptr;
}//ctor

Nodo::~Nodo()
{

}//dtor

