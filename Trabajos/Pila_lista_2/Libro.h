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
		char nombre[15];
		char autor[15];
		char editorial[15];
};

#endif // LIBRO_H
