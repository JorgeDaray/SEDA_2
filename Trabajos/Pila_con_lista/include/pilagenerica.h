#ifndef PILAGENERICA_H
#define PILAGENERICA_H
#include <iostream>

template <class T>
class PilaGenerica
{
     class NodoPila
     {
        public:
        NodoPila* siguiente;
        T elemento;
        NodoPila(T x)
        {
            elemento = x;
            siguiente = NULL;
        }
    };
    NodoPila* cima;
    public:
    PilaGenerica ()
    {
        cima = NULL;
    }
    void insertar(T elemento);
    T quitar();
    T cimaPila(); const
    bool pilaVacia(); const
    void limpiarPila();
    ~PilaGenerica()
    {
        limpiarPila();
    }
};

#endif // PILAGENERICA_H
