/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include "Pila.h"
#include "Nodo.h"
#include "Libro.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Pila::push(Libro book)
{
    Nodo *temp = new Nodo();
    temp->Datos = book;
    if (top == nullptr)
    {
        top = temp;
    }
    else
    {
        temp ->next = top;
        top = temp;
    }
    top = temp;
}

void Pila::pop()
{
    Nodo *temp;
    temp = top;
    if(top != nullptr)
    {
        temp = top;
        top = temp->next;
        delete(temp);
    }
    if(top == nullptr)
    {
        cout << "Se elimino todo correctamente" <<endl;
    }
}

void Pila::mostrar()
{
    Nodo *temp;
    temp = top;
    cout << left << setw( 40 ) << "nombre"
    << setw( 40 ) << "autor" << setw( 40 ) << right << fixed
    << showpoint << "editorial" << endl;
    while(temp)
    {
        temp ->Datos.imprimir_registro();
        temp = temp ->next;
    }
}

Pila::Pila()
{
    top = nullptr;
}//ctor

Pila::~Pila()
{

}//dtor
