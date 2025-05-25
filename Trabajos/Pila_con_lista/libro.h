#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>

unsigned namespace std;

class Libro
{
    public:
        Libro();
        void establecernombre(string);
        string obtenernombre();
        void establecerautor(string);
        string obtenerautor();
        void establecereditorial(string);
        string obtenereditorial();
        void imprimir_registro();
        ~Libro();
    private:
		string nombre[20];
		string autor[20];
		string Editorial[15];
		Libro();
		~Libro();
};

#endif // LIBRO_H
