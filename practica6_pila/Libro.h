/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>

using namespace std;

class Libro
{
    public:
        Libro(int = 0, string = "", string = "", string = "");
        void establecerposicion(int);
        int obtenerposicion() const;
        void establecernombre(string);
        string obtenernombre() const;
        void establecerautor(string);
        string obtenerautor() const;
        void establecereditorial(string);
        string obtenereditorial() const;
        void imprimir_registro();
        ~Libro();
    private:
        int posicion;
		char nombre[40];
		char autor[40];
		char editorial[40];
};

#endif // LIBRO_H

