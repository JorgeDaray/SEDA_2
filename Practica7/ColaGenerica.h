#ifndef COLAGENERICA_H_INCLUDED
#define COLAGENERICA_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

 // archivo ColaGenerica.h
template <class T>
class ColaGenerica
{
protected:
    class NodoCola
    {
        public:
        NodoCola* siguiente;
        T elemento;
        NodoCola (T x)
        {
            elemento = x;
            siguiente = NULL;
        }
    };
    NodoCola* frente;
    NodoCola* final;
    public:
    ColaGenerica()
    {
        frente = final = NULL;
    }
    void insertar(T elemento);
    T quitar();
    void borrarCola();
    T frenteCola()const;
    bool colaVacia() const;
    void GenerarMostrar(fstream&);
    void recuperar();
    void mostrarCola(fstream&);
    ~ColaGenerica()
    {
        borrarCola ();
    }
};

#endif // COLAGENERICA_H_INCLUDED
