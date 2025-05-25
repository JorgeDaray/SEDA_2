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
    longitud = (longitud < 15 ? longitud : 14);
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
    longitud = (longitud < 15 ? longitud : 14);
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
    longitud = (longitud < 15 ? longitud : 14);
    strncpy(editorial, valorEditorial, longitud);
    editorial[longitud] = '\0';
}//fin void establecerDeporte
string Libro::obtenereditorial()const
{
    return editorial;
}

void Libro::imprimir_registro()
{
    cout << left << setw( 16 ) << nombre
    << setw( 16 ) << autor << setw( 16 ) << right << fixed
    << showpoint << editorial << endl;
}

Libro::~Libro()
{

}//dtor
