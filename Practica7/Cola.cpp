#include "Cola.h"
#include "Nodo.h"
#include "NumeroSuerte.h"
#include <iostream>
#include <iomanip>
/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */

using namespace std;

/*void Cola::push(NumeroSuerte elemento)
{
    Nodo *temp = new Nodo();
    temp->Datos = elemento;
    if (frente == nullptr)
    {
        frente = temp;
    }
    else
    {
        temp ->next = frente;
        frente = temp;
    }
    frente = temp;
}*/

void Cola::insertar(NumeroSuerte elemento)
{
    Nodo *nuevo = new Nodo();
    nuevo->Datos = elemento;
    nuevo->next = NULL;
    if (frente == nullptr)
    {
        raiz = nuevo;
        frente = nuevo;
    }
    else {
        frente->next = nuevo;
        frente = nuevo;
    }
}

NumeroSuerte Cola::borrar()
{
    Nodo *temp;
    temp = raiz;
    if(frente != nullptr)
    {
        temp = raiz;
        raiz = temp->next;
        delete(temp);
    }
    if(raiz == nullptr)
    {
        cout << "Se elimino todo correctamente" <<endl;
    }
}

void Cola::mostrar()
{
    Nodo *temp;
    temp = frente;
    cout << left << setw( 40 ) << "nombre"
    << setw( 40 ) << "autor" << setw( 40 ) << right << fixed
    << showpoint << "editorial" << endl;
    while(temp)
    {
        temp ->Datos.imprimir_registro();
        temp = temp ->next;
    }
}

Cola::Cola()
{
    frente = nullptr;
    //ctor
}

Cola::~Cola()
{
    //dtor
}
