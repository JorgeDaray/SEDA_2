#include "NumeroSuerte.h"

/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

NumeroSuerte::NumeroSuerte(int valorPosicion)
{
    establecerposicion(valorPosicion);
}//ctor

void NumeroSuerte::establecerposicion(int valorPosicion)
{
    posicion = valorPosicion;
}
int NumeroSuerte::obtenerposicion()const
{
    return posicion;
}


void NumeroSuerte::imprimir_registro()
{
    cout << left << setw( 40 ) << posicion << endl;
}

NumeroSuerte::~NumeroSuerte()
{
    //dtor
}
