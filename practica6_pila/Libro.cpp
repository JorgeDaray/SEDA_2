/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include "Libro.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Libro::Libro(int valorPosicion, string valorNombre, string valorAutor, string valorEditorial)
{
    establecerposicion(valorPosicion);
    establecernombre(valorNombre);
    establecerautor(valorAutor);
    establecereditorial(valorEditorial);
}//ctor

void Libro::establecerposicion(int valorPosicion)
{
    posicion = valorPosicion;
}
int Libro::obtenerposicion()const
{
    return posicion;
}
//Establece el valor del nombre
void Libro::establecernombre(string cadenaNombre)
{
    const char*valorNombre = cadenaNombre.data();
    int longitud = cadenaNombre.size();
    longitud = (longitud < 40 ? longitud : 39);
    strncpy(nombre, valorNombre, longitud);
    nombre[longitud] = '\0';
}//fin void establecerNombre

string Libro::obtenernombre()const
{
    return nombre;
}

//Establece el valor del deporte
void Libro::establecerautor(string cadenaAutor)
{
    const char*valorAutor = cadenaAutor.data();
    int longitud = cadenaAutor.size();
    longitud = (longitud < 40 ? longitud : 39);
    strncpy(autor, valorAutor, longitud);
    autor[longitud] = '\0';
}//fin void establecerDeporte
string Libro::obtenerautor()const
{
    return autor;
}

//Establece el valor del deporte
void Libro::establecereditorial(string cadenaEditorial)
{
    const char*valorEditorial = cadenaEditorial.data();
    int longitud = cadenaEditorial.size();
    longitud = (longitud < 40 ? longitud : 39);
    strncpy(editorial, valorEditorial, longitud);
    editorial[longitud] = '\0';
}//fin void establecerDeporte
string Libro::obtenereditorial()const
{
    return editorial;
}

void Libro::imprimir_registro()
{
    cout << left << setw( 40 ) << nombre
    << setw( 40 ) << autor << setw( 40 ) << right << fixed
    << showpoint << editorial << endl;
}

Libro::~Libro()
{

}//dtor
