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
